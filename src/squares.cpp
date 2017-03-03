#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <stdlib.h>
int a=0,b;
void talkerCallback(const std_msgs::String::ConstPtr& msg2)
{
   b= atoi(msg2 ->data.c_str());
  a=b*b;
}
int main(int argc, char **argv)
{  
  ros::init(argc, argv, "listener");  
  ros::NodeHandle n;
  ros::Publisher chatter_pub2 = n.advertise<std_msgs::String>("topic_squares", 1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, talkerCallback);
  ros::Rate loop_rate(1);
  while(ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << a;
    msg.data = ss.str();
    chatter_pub2.publish(msg);
    
    loop_rate.sleep();
    ros::spinOnce();
  }  
  ros::spin();
  return 0;
}
