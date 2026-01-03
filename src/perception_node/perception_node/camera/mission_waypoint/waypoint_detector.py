import rclpy
from rclpy.node import Node
from drone_msgs.msg import Waypoint

class WaypointDetector(Node):
    def __init__(self):
        super().__init__('waypoint_detector')
        self.pub = self.create_publisher(Waypoint, '/waypoint', 10)
        self.timer = self.create_timer(1.0, self.tick)

    def tick(self):
        msg = Waypoint()
        msg.x = 1.0
        msg.y = 0.0
        msg.z = 1.5
        msg.yaw = 0.0
        msg.valid = True
        self.pub.publish(msg)
        self.get_logger().info('Publish dummy waypoint')

def main():
    rclpy.init()
    node = WaypointDetector()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
