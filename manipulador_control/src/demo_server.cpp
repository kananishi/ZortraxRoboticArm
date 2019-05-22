#include "ros/ros.h"
#include "manipulador_control/demo.h"

bool compute(manipulador_control::demo::Request &req,
	       	manipulador_control::demo::Response &res){
	if(req.x == 0 && req.y == 0 && req.z == 0){
		res.t1 = 0;
		res.t2 = 0;
		res.t3 = 0;
		res.t4 = 0;
		res.t5 = 0;
	
		ROS_INFO("Reset");
	}
	ROS_INFO("First: %f", res.t1);
	return true;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "demo_server");
	ros::NodeHandle n;
	
	ros::ServiceServer service = n.advertiseService("demo",compute);
	ROS_INFO("Ready to reset");

	ros::spin();

	return 0;

}



