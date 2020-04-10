#include <ros/ros.h>
#include <std_msgs/Char.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "wasd");
    ros::NodeHandle nh;
    ros::Publisher wasd_pub = nh.advertise<std_msgs::Char>("keys", 1000);
    ros::Rate loop_rate(10);
    while (ros::ok()) {
	std_msgs::Char msg;
	char key = 0; 
	cin >> key;
	if (key != 209) msg.data = key;
	ROS_INFO("key code is: %d \n", msg.data);
	wasd_pub.publish(msg);
	ros::spinOnce();
	loop_rate.sleep();
    }
    
    return 0;
}
