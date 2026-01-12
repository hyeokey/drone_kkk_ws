import math
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy

from px4_msgs.msg import (
    OffboardControlMode,
    TrajectorySetpoint,
    VehicleCommand,
    VehicleLocalPosition,
    VehicleStatus
)

class MissionWaypoint(Node):

    def __init__(self):
        super().__init__("mission_waypoint")

        self.qos_px4 = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )

        self.offboard_mode_pub = self.create_publisher(
            OffboardControlMode, "/fmu/in/offboard_control_mode", 10
        )
        self.traj_pub = self.create_publisher(
            TrajectorySetpoint, "/fmu/in/trajectory_setpoint", 10
        )
        self.cmd_pub = self.create_publisher(
            VehicleCommand, "/fmu/in/vehicle_command", 10
        )

        self.local_pos_sub = self.create_subscription(
            VehicleLocalPosition, "/fmu/out/vehicle_local_position_v1", self.local_pos_cb, self.qos_px4
        )
        self.status_sub = self.create_subscription(
            VehicleStatus, "/fmu/out/vehicle_status_v1", self.status_cb, self.qos_px4
        )

        self.local_pos = None
        self.nav_state = None
        self.arm_state = None
        self.system_id = 1
        
        self.target_x = 10.0
        self.target_y = 0.0
        self.target_z = -2.0
        
        self.phase = "WAIT"
        self.setpoint_count = 0

        self.timer = self.create_timer(0.05, self.loop)
        self.get_logger().info("Node started")

    def local_pos_cb(self, msg):
        self.local_pos = msg

    def status_cb(self, msg):
        self.nav_state = msg.nav_state
        self.arm_state = msg.arming_state
        self.system_id = msg.system_id

    def loop(self):
        self.publish_offboard_control_mode()

        if self.local_pos is None or self.nav_state is None:
            return

        if self.phase == "WAIT":
            self.phase = "WARMUP"

        elif self.phase == "WARMUP":
            self.publish_setpoint(0.0, 0.0, 0.0)
            self.setpoint_count += 1
            if self.setpoint_count >= 100:
                self.phase = "OFFBOARD"

        elif self.phase == "OFFBOARD":
            self.set_offboard_mode()
            if self.nav_state == 14:
                self.phase = "ARM"
            else:
                self.publish_setpoint(0.0, 0.0, 0.0)

        elif self.phase == "ARM":
            self.arm()
            if self.arm_state == 2:
                self.phase = "TAKEOFF"
            else:
                self.publish_setpoint(0.0, 0.0, 0.0)

        elif self.phase == "TAKEOFF":
            self.publish_setpoint(0.0, 0.0, self.target_z)
            if self.local_pos.z < -1.5:
                self.get_logger().info("Takeoff OK -> Moving to Target")
                self.phase = "NAV"

        elif self.phase == "NAV":
            dist = math.sqrt((self.target_x - self.local_pos.x)**2 + 
                             (self.target_y - self.local_pos.y)**2)
            
            self.get_logger().info(f"Dist to Target: {dist:.2f}m | Curr X: {self.local_pos.x:.2f}", throttle_duration_sec=1.0)

            if dist < 0.5:
                self.phase = "HOVER"
                self.get_logger().info("Target Reached")
            else:
                self.publish_setpoint(self.target_x, self.target_y, self.target_z)

        elif self.phase == "HOVER":
            self.publish_setpoint(self.target_x, self.target_y, self.target_z)

    def now_us(self):
        return self.get_clock().now().nanoseconds // 1000

    def publish_offboard_control_mode(self):
        msg = OffboardControlMode()
        msg.position = True
        msg.velocity = False
        msg.acceleration = False
        msg.attitude = False
        msg.body_rate = False
        msg.timestamp = self.now_us()
        self.offboard_mode_pub.publish(msg)

    def publish_setpoint(self, x, y, z, yaw=0.0):
        msg = TrajectorySetpoint()
        msg.position = [float(x), float(y), float(z)]
        msg.yaw = yaw
        msg.timestamp = self.now_us()
        self.traj_pub.publish(msg)

    def send_cmd(self, command, p1=0.0, p2=0.0):
        msg = VehicleCommand()
        msg.command = int(command)
        msg.param1 = float(p1)
        msg.param2 = float(p2)
        msg.target_system = int(self.system_id)
        msg.target_component = 1
        msg.source_system = 1
        msg.source_component = 1
        msg.from_external = True
        msg.timestamp = self.now_us()
        self.cmd_pub.publish(msg)

    def arm(self):
        self.send_cmd(VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, p1=1.0)

    def set_offboard_mode(self):
        self.send_cmd(VehicleCommand.VEHICLE_CMD_DO_SET_MODE, p1=1.0, p2=6.0)

def main(args=None):
    rclpy.init(args=args)
    node = MissionWaypoint()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == "__main__":
    main()