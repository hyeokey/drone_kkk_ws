#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

#include <gz/transport/Node.hh>
#include <gz/msgs/laserscan.pb.h>

class LidarScanBridge : public rclcpp::Node
{
public:
  LidarScanBridge()
  : Node("lidar_scan_bridge")
  {
    scan_pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>(
      "/scan", 10);

    std::string gz_topic =
      "/world/default/model/x500_lidar_2d_0/link/link/sensor/lidar_2d_v2/scan";

    if (!gz_node_.Subscribe(gz_topic, &LidarScanBridge::gzCallback, this))
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to subscribe Gazebo LaserScan");
    }

    RCLCPP_INFO(this->get_logger(), "Bridging Gazebo LaserScan → ROS /scan");
  }

private:
  void gzCallback(const gz::msgs::LaserScan &msg)
  {
    sensor_msgs::msg::LaserScan ros_scan;

    ros_scan.header.stamp = this->now();
    ros_scan.header.frame_id = "base_link";

    ros_scan.angle_min = msg.angle_min();
    ros_scan.angle_max = msg.angle_max();
    ros_scan.angle_increment = msg.angle_step();

    ros_scan.time_increment = 0.0;
    ros_scan.scan_time = 1.0;

    ros_scan.range_min = msg.range_min();
    ros_scan.range_max = msg.range_max();

    const int n = msg.ranges_size();
    ros_scan.ranges.resize(n);
    ros_scan.intensities.resize(n);

    for (int i = 0; i < n; ++i)
    {
      ros_scan.ranges[i] = msg.ranges(i);
      ros_scan.intensities[i] = 0.0f;  // Gazebo 기본 LiDAR는 intensity 없음
    }

    scan_pub_->publish(ros_scan);
  }

  gz::transport::Node gz_node_;
  rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr scan_pub_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LidarScanBridge>());
  rclcpp::shutdown();
  return 0;
}
