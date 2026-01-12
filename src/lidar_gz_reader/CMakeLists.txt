cmake_minimum_required(VERSION 3.8)
project(lidar_gz_reader)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

find_package(gz-transport13 REQUIRED)
find_package(gz-msgs10 REQUIRED)

add_executable(lidar_reader src/lidar_reader.cpp)

target_link_libraries(lidar_reader
  gz-transport13
  gz-msgs10
)

ament_target_dependencies(lidar_reader
  rclcpp
  sensor_msgs
)

install(TARGETS lidar_reader
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
