#include "ros/ros.h"
#include "manipulador_control/demo.h"
#include <cstdlib>

int main(int argc, char **argv){
	ros::init(argc, argv, "demo_client");

	if(argc != 4){
		ROS_INFO("set X, Y, Z");
		return 1;
	}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<manipulador_control::demo>("demo");

	manipulador_control::demo srv;

	srv.request.x = atof(argv[1]);
	srv.request.y = atof(argv[2]);	
	srv.request.z = atof(argv[3]);	

	if(client.call(srv)){
		ROS_INFO("%f", srv.response.t1);
	}

	else{
		ROS_ERROR("Fail to call service");
		return 1;
	}

	return 0;

}
