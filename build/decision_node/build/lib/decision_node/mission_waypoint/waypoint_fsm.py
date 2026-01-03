import rclpy
from rclpy.node import Node
from drone_msgs.msg import Waypoint

class WaypointFSM(Node):
    def __init__(self):
        super().__init__('waypoint_fsm')
        self.sub = self.create_subscription(Waypoint, '/waypoint', self.cb, 10)

    def cb(self, msg: Waypoint):
        if msg.valid:
            self.get_logger().info(f'Received waypoint: x={msg.x:.2f}, y={msg.y:.2f}, z={msg.z:.2f}, yaw={msg.yaw:.2f}')

def main():
    rclpy.init()
    node = WaypointFSM()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
