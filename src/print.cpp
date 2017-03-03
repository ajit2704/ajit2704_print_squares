#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>
void talkerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("topic_number=    %s", msg->data.c_str());
}
void listenerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("topic_square=    %s", msg->data.c_str());
}
int main(int argc, char **argv)
{  
  ros::init(argc, argv, "listener2");  
  ros::NodeHandle n;  
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, talkerCallback);
  ros::Subscriber sub2 = n.subscribe("topic_squares", 1000, listenerCallback);  
  ros::spin();
  return 0;
}
