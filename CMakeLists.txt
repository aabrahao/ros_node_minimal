cmake_minimum_required(VERSION 3.8)
project(ros_node_minimum)

# C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler
add_compile_options(-Wall -Wextra -Wpedantic -Wunused-parameter)

# ROS dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

# Executable
add_executable(${PROJECT_NAME}
      main.cpp
      Ros.h
      Ros.cpp
      # add all .cpp and .h
      )

# ROS
ament_target_dependencies(${PROJECT_NAME}
      rclcpp 
      std_msgs 
      sensor_msgs)

install(TARGETS ${PROJECT_NAME}
      DESTINATION lib/${PROJECT_NAME})

ament_package()
