#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "publisher");	// initiate node and set the name(unique)
	ros::NodeHandle n;	// Handler of the process
	
	
	// Set a publisher and tell the name and type to master 
	ros::Publisher firstJoint = n.advertise<std_msgs::Float64>("/manipulador/first_controller/command", 1000);
	ros::Publisher secondJoint = n.advertise<std_msgs::Float64>("/manipulador/second_controller/command", 1000);
	ros::Publisher thirdJoint = n.advertise<std_msgs::Float64>("/manipulador/third_controller/command", 1000);
	ros::Publisher fourthJoint = n.advertise<std_msgs::Float64>("/manipulador/fourth_controller/command", 1000);
	ros::Publisher fifthJoint = n.advertise<std_msgs::Float64>("/manipulador/fifth_controller/command", 1000);

	
	// frequecy to send data in Hz
	ros::Rate loop_rate(10); 
	
	// Stop the node if receives a sign to do so
	while (ros::ok())
	{
		
		std::string input;	// receive input from user

		std::cout << "Joint:"<<std::endl;
		std::getline(std::cin,input); // message
		int joint = stoi(input);

		std::cout << "Angle:"<<std::endl;
		std::getline(std::cin,input); // message

		std_msgs::Float64 angle;
		angle.data = stof(input);
		//ROS_INFO("%s", msg.data.c_str());
		switch(joint){
			case 1:
				firstJoint.publish(angle);
				break;

			case 2:
				secondJoint.publish(angle);
				break;

			case 3:
				thirdJoint.publish(angle);
				break;

			case 4:
				fourthJoint.publish(angle);
				break;

			case 5:
				fifthJoint.publish(angle);
				break;

			default:
				ROS_ERROR("Invalid Joint");
				break;
		}
		
		ros::spinOnce();	// ROS updates and publish message to topic
		loop_rate.sleep(); // sleep to get a 10 Hz frequency
	}
	return 0;
}
