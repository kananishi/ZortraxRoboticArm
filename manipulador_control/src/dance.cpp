#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include <sstream>

void publish(std_msgs::Float64,std_msgs::Float64,std_msgs::Float64,std_msgs::Float64,std_msgs::Float64,ros::Publisher*);
void print(const control_msgs::JointControllerState msg){
	ROS_INFO("OI");
	ROS_INFO("Entrou: %f", msg.set_point);	
}
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
	ros::Publisher joints[5] = {firstJoint,secondJoint,thirdJoint,fourthJoint,fifthJoint};

	std_msgs::Float64 th1, th2, th3, th4, th5;
	int state=0;

	ros::Subscriber jointState = n.subscribe("/manipulador/first_controller/state",1000,print);
	// frequecy to send data in Hz
	ros::Rate loop_rate(1); 
	// Stop the node if receives a sign to do so
	while (ros::ok())
	{
		if(state > 3)
			state = 0;
		
		switch(state){
			case 0:
				th1.data = 0;
				th2.data = 0;
				th3.data = 0;
				th4.data = 0;
				th5.data = 0;
				publish(th1,th2,th3,th4,th5,joints);
				break;

			case 1:
				th1.data = 1;
				th2.data = 0;
				th3.data = 0;
				th4.data = 0;
				th5.data = 0;
				publish(th1,th2,th3,th4,th5, joints);
				break;

			case 2:
				th1.data = 0;
				th2.data = 0;
				th3.data = 0;
				th4.data = 0;
				th5.data = 0;
				publish(th1,th2,th3,th4,th5,joints);
				break;

			case 3:
				th1.data = -1;
				th2.data = 0;
				th3.data = 0;
				th4.data = 0;
				th5.data = 0;	
				publish(th1,th2,th3,th4,th5,joints);
				break;
		}

		state++;
		ros::spinOnce();	// ROS updates and publish message to topic
		loop_rate.sleep(); // sleep to get a 10 Hz frequency
		//sleep(1);
	}
	return 0;
}	


void publish(std_msgs::Float64 th1, std_msgs::Float64 th2, std_msgs::Float64 th3, std_msgs::Float64 th4, std_msgs::Float64 th5, ros::Publisher* joints){
	joints[0].publish(th1);
	joints[1].publish(th2);
	joints[2].publish(th3);
	joints[3].publish(th4);
	joints[4].publish(th5);
}