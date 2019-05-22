#include "ros/ros.h"
#include "manipulador_control/ikine.h"

bool ikine(manipulador_control::ikine::Request &req,
	       	manipulador_control::ikine::Response &res){
	if(req.x == 0 && req.y == 0 && req.z == 0){
		res.th1 = 0;
		res.th2 = 0;
		res.th3 = 0;
		res.th4 = 0;
		res.th5 = 0;
	
		ROS_INFO("Reset");
	}
	else{
		res.th1 = -1;
	}
	ROS_INFO("First: %f", res.th1);
	return true;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "ikine_server");
	ros::NodeHandle n;
	
	ros::ServiceServer service = n.advertiseService("jointControl",ikine);
	ROS_INFO("Ready to compute");

	ros::spin();

	return 0;

}



