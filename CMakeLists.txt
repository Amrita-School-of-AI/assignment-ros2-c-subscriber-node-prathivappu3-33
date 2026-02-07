cmake_minimum_required(VERSION 3.8)
project(ros2_subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Create executable
add_executable(subscriber_node src/subscriber_node.cpp)

# Link dependencies
ament_target_dependencies(subscriber_node
  rclcpp
  std_msgs
)

# Install executable
install(TARGETS
  subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
