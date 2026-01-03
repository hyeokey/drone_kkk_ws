# drone_kkk_ws
ros2 기반 드론 자율주행 프로젝트 워크스페이스.
본 레파지토리는 ros2 노드(제어/인지/메시지)만 포함되어 있음.
도커 사용안하고 그냥 호스트(로컬)에서 clone 해주면 됨.
호스트에서 QGC, ros2, PX4/gz 다 돌리는 구조.

# how to clone this repository(git 처음이신 분들 주목)
git --version(git 설치되어 있는지 확인 명령어)

sudo apt update (없으면 설치)
sudo apt install git (없으면 설치)

git clone https://github.com/hyeokey/drone_kkk_ws.git
cd drone_kkk_ws

# px4는 home에서 설치하면 됩니다. (이미 설치되어 있으면 pass)
cd ~
git clone https://github.com/PX4/PX4-Autopilot.git --recursive

# build
cd drone_kkk_ws
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash

# px4 SITL 실행(새 터미널에서)
cd PX4-Autopilot
make px4_sitl gz_x500

# waypoint FSM 실행(현재는 기본적인 코드만 들어가 있음)
source ~/drone_kkk_ws/install/setup.bash
ros2 run decision_node waypoint_fsm

# Micro XRCE DDS Agnet 설치 및 실행(ros랑 px4 브릿지 역할)
cd ~
git clone https://github.com/eProsima/Micro-XRCE-DDS-Agent.git
cd Micro-XRCE-DDS-Agent
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
sudo ldconfig

MicroXRCEAgent udp4 -p 8888

# gazebo <-> ros2 bridge (ros_gz_bridge 패키지가 필요)
sudo apt update
sudo apt install ros-humble-ros-gz-bridge ros-humble-ros-gz-interfaces

ros2 pkg list | grep ros_gz(설치 확인 명령어)
ros_gz_bridge (올바른 출력)
ros_gz_interfaces (올바른 출력)

# Waypoint 기반 자율비행 제어 로직은 아래 파일에 작성하면 됩니다.
drone_kkk_ws/src/decision_node/decision_node/mission_waypoint/waypoint_fsm.py






