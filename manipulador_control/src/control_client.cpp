#include "ros/ros.h"
#include "manipulador_control/ikine.h"
#include "std_msgs/Float64.h"
#include <cstdlib>

void input(manipulador_control::ikine *srv){

	std::string input;	// receive input from user

	std::cout << "Enter Coordinates:"<<std::endl;

	std::cout << "x = ";
	std::getline(std::cin,input); // message
	srv->request.x = stof(input);
/*
	std::cout << "y = ";
	std::getline(std::cin,input); // message
	srv->request.y = stof(input);

	std::cout << "z = ";
	std::getline(std::cin,input); // message
	srv->request.z = stof(input);
*/	
}

int main(int argc, char **argv){
	ros::init(argc, argv, "ikine_client");
	ros::NodeHandle n;

	// Set a publisher and tell the name and type to master 
	ros::Publisher firstJoint = n.advertise<std_msgs::Float64>("/manipulador/first_controller/command", 1000);
	ros::Publisher secondJoint = n.advertise<std_msgs::Float64>("/manipulador/second_controller/command", 1000);
	ros::Publisher thirdJoint = n.advertise<std_msgs::Float64>("/manipulador/third_controller/command", 1000);
	ros::Publisher fourthJoint = n.advertise<std_msgs::Float64>("/manipulador/fourth_controller/command", 1000);
	ros::Publisher fifthJoint = n.advertise<std_msgs::Float64>("/manipulador/fifth_controller/command", 1000);


	
	ros::ServiceClient client = n.serviceClient<manipulador_control::ikine>("jointControl");

	manipulador_control::ikine srv;
	ros::Rate loop_rate(10); 
	
	while(ros::ok()){
		input(&srv);

		if(client.call(srv)){
			ROS_INFO("Setting joints %f", srv.response.th1);
			std_msgs::Float64 th1, th2, th3, th4, th5;
			th1.data = srv.response.th1;
			th2.data = srv.response.th2;
			th3.data = srv.response.th3;
			th4.data = srv.response.th4;
			th5.data = srv.response.th5;
			firstJoint.publish(th1);
			secondJoint.publish(th2);
			thirdJoint.publish(th3);
			fourthJoint.publish(th4);
			fifthJoint.publish(th5);
			
		}

		else{
			ROS_ERROR("Fail to call service");
			return 1;
		}

		ros::spinOnce();
		loop_rate.sleep(); // sleep to get a 10 Hz frequency

	}

	return 0;

}
