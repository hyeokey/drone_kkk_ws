# CMake generated Testfile for 
# Source directory: /home/dong/drone_kkk_ws/PX4-Autopilot/src/lib/system_identification
# Build directory: /home/dong/drone_kkk_ws/build/px4/src/lib/system_identification
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit-arx_rls_test "/home/dong/drone_kkk_ws/build/px4/unit-arx_rls_test")
set_tests_properties(unit-arx_rls_test PROPERTIES  WORKING_DIRECTORY "/home/dong/drone_kkk_ws/build/px4" _BACKTRACE_TRIPLES "/home/dong/drone_kkk_ws/PX4-Autopilot/cmake/px4_add_gtest.cmake;72;add_test;/home/dong/drone_kkk_ws/PX4-Autopilot/src/lib/system_identification/CMakeLists.txt;40;px4_add_unit_gtest;/home/dong/drone_kkk_ws/PX4-Autopilot/src/lib/system_identification/CMakeLists.txt;0;")
add_test(unit-system_identification_test "/home/dong/drone_kkk_ws/build/px4/unit-system_identification_test")
set_tests_properties(unit-system_identification_test PROPERTIES  WORKING_DIRECTORY "/home/dong/drone_kkk_ws/build/px4" _BACKTRACE_TRIPLES "/home/dong/drone_kkk_ws/PX4-Autopilot/cmake/px4_add_gtest.cmake;72;add_test;/home/dong/drone_kkk_ws/PX4-Autopilot/src/lib/system_identification/CMakeLists.txt;41;px4_add_unit_gtest;/home/dong/drone_kkk_ws/PX4-Autopilot/src/lib/system_identification/CMakeLists.txt;0;")
