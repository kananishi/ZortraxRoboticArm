#include "ros/ros.h"
#include "manipulador_control/ikine.h"

bool ikine(manipulador_control::ikine::Request &req,
	       	manipulador_control::ikine::Response &res){
	if(req.x == 0){
		res.th1 = 0;
		res.th2 = 0;
		res.th3 = 0;
		res.th4 = 0;
		res.th5 = 0;
	
		ROS_INFO("Reset");
	}
	if(req.x == 1){
		res.th1 = 0;
		res.th2 = 1.3;
		res.th3 = -0.5;
		res.th4 = -1;
		res.th5 = 0;
	}
	if(req.x == 2){
		res.th1 = 3.15;
		res.th2 = 0.5;
		res.th3 = -0.5;
		res.th4 = 0;
		res.th5 = 0;
	}
	if(req.x == 3){
		res.th1 = 3.15;
		res.th2 = 1.3;
		res.th3 = -0.5;
		res.th4 = -1;
		res.th5 = 0;
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



