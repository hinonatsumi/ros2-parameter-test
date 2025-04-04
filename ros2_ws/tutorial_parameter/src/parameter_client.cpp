#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("parameter_client");
  auto client = std::make_shared<rclcpp::SyncParametersClient>(node, "parameter");
  while(!client->wait_for_service(1s) && rclcpp::ok()){
    RCLCPP_INFO(node->get_logger(), "Wait for service...");
  }
  auto parameters = client->get_parameters({"int_val", "double_val", "str_val"});
  for(auto &param : parameters){
    std::cout << "Name : " << param.get_name() << std::endl
	      << "Type : " << param.get_type_name() << std::endl
	      << "Val : " << param.value_to_string() << std::endl << std::endl;
  }

  rclcpp::shutdown();
  return 0;
}
