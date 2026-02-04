#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
  PublisherNode() : Node("publisher_node"), counter_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("/counter", 10);

    timer_ = this->create_wall_timer(
      500ms,
      std::bind(&PublisherNode::timer_callback, this));

    RCLCPP_INFO(this->get_logger(), "Publisher node started");
  }

private:
  void timer_callback()
  {
    std_msgs::msg::String message;
    message.data = "Count: " + std::to_string(counter_);

    publisher_->publish(message);

    RCLCPP_INFO(
      this->get_logger(),
      "Publishing: '%s'",
      message.data.c_str());

    counter_++;
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  int counter_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PublisherNode>());
  rclcpp::shutdown();
  return 0;
}
