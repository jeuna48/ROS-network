#include "ros/ros.h"                         
#include "ros_test/srvTutorial.h" 

bool calculation(ros_test::srvTutorial::Request  &req,
         ros_test::srvTutorial::Response &res)
{
  res.result = req.a + req.b;  

  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.result);

  return true;
}

int main(int argc, char **argv)                     
{
  ros::init(argc, argv, "ros_tutorial_srv_server"); 
  ros::NodeHandle nh;                               


  ROS_INFO("ready srv server!");

  ros::spin();  

  return 0;
}