[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/0r2ZNa8b)
# Assignment: ROS2 C++ Subscriber Node

**Course:** ROS2 Fundamentals  
**Build System:** ament_cmake

## Objective

The goal of this assignment is to verify your understanding of:

1. How to create a ROS2 Subscriber node.
2. How to subscribe to messages using `std_msgs/msg/String`.
3. How to process incoming messages with callbacks.

## Problem Statement

You must complete the provided skeleton code to create a ROS2 node that subscribes to a topic and logs received messages.

### Requirements

1. **Source Code (`src/subscriber_node.cpp`)**:
   - Implement a class `SubscriberNode` that inherits from `rclcpp::Node`.
   - Initialize the node with the name `"subscriber_node"`.
   - Create a subscription to the topic `"/chatter"` with type `std_msgs::msg::String`.
   - Inside the subscription callback:
     - Log the received message using `RCLCPP_INFO` with format: `"I heard: 'MESSAGE'"` where MESSAGE is the received data.

2. **Build Configuration (`CMakeLists.txt`)**:
   - Add an executable target named `subscriber_node` compiled from `src/subscriber_node.cpp`.
   - Link dependencies for `rclcpp` and `std_msgs`.
   - Ensure the executable is installed to `lib/${PROJECT_NAME}`.

3. **Package Metadata (`package.xml`)**:
   - Add the missing dependency tags for `rclcpp` and `std_msgs`.

## How to Test Locally

Before pushing to GitHub, ensure your code runs locally:

```bash
# Terminal 1: Build and run the subscriber
colcon build --packages-select ros2_subscriber
source install/setup.bash
ros2 run ros2_subscriber subscriber_node

# Terminal 2: Publish test messages
ros2 topic pub /chatter std_msgs/msg/String "data: 'Hello ROS2'" --once
```

#### Expected Output (in subscriber terminal):

```shell
[INFO] [1700000000.123456789] [subscriber_node]: I heard: 'Hello ROS2'
```
