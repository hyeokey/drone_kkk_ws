# clone 해주기(필수)
git clone --recurse-submodules -b hyeokey https://github.com/hyeokey/drone_kkk_ws.git


# 워크 스페이스 구조
drone_kkk_ws/
 ├── src/
 │   ├── drone_description/     # URDF + robot_state_publisher
 │   ├── lidar_gz_reader/       # Gazebo LiDAR → ROS2 bridge
 │   ├── decision_node/         # 제어 로직
 │   └── px4_msgs/              # PX4 ROS2 메시지 (submodule)
 ├── build/
 ├── install/
 └── log/


# 빌드(필수)
cd ~/drone_kkk_ws
rm -rf build install log   
colcon build
source install/setup.bash

# rviz + urdf 시각화
ros2 launch drone_description state_pub.launch.py

# lidar 달린 드론 모델 실행
cd ~/PX4-Autopilot
make px4_sitl gz_x500_lidar_2d

# ros2 <-> gz 브릿지 노드
ros2 run lidar_gz_reader lidar_reader

# 단축키 설정
cd ~/drone_kkk_ws 
nano ~/.bashrc # 창 열리면 아래 명령어 복붙하기

# ROS 2 & Workspace Shortcut
alias ss='source /opt/ros/humble/setup.bash && source ~/drone_kkk_ws/install/setup.bash && echo "ROS 2 Humble & Drone WS Loaded!"'
# ctrl + o -> enter -> ctrl + x
# 그 후 source ~/.bashrc 입력해주기
