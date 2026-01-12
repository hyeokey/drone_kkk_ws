from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg_path = get_package_share_directory('drone_description')
    urdf_file = os.path.join(pkg_path, 'urdf', 'drone.urdf.xacro')

    return LaunchDescription([

        # robot_state_publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{
                'robot_description': Command(['xacro ', urdf_file])
            }]
        ),

        # RViz
        Node(
            package='rviz2',
            executable='rviz2',
            output='screen'
        )
    ])
