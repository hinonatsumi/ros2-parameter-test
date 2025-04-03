#include <rclcpp/rclcpp.hpp>
#include <thread>

int main(int argc, char **argv)
{
  rclcpp::init(argc,argv);
  auto node = rclcpp::Node::make_shared("parameter");
  int int_val = node->declare_parameter<int>("int_val", 0);
  double double_val = node->declare_parameter<double>("double_val", 1.0);
  std::string str_val = node->declare_parameter<std::string>("str_val", "hello");

  std::thread([&]{rclcpp::spin(node);}).detach();

  rclcpp::WallRate loop(1);
  while(rclcpp::ok()){
    node->get_parameter("int_val", int_val);
    node->get_parameter("double_val", double_val);
    node->get_parameter("std_val", str_val);
    RCLCPP_INFO(node->get_logger(), "int : %d, double : %lf, str : %s",
		int_val, double_val, str_val.c_str());
    loop.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
