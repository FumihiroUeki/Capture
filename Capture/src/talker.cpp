#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/opencv.hpp>
#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle nh("~");

	image_transport::ImageTransport it(nh);
	image_transport::Publisher image_pub = it.advertise("image", 10);

	cv::VideoCapture cap(1);
	cv::Mat capture;
	cv::Mat dst;

	if(!cap.isOpened()){
		std::cerr << "can not open camera." << std::endl;
		return -1;
	}

	ros::Rate looprate(10);

	while(ros::ok()){

		cap >> capture;
		cv::resize(capture, dst, cv::Size(), 0.5, 0.5);
		sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", dst).toImageMsg();
		image_pub.publish(msg);
		
		ros::spinOnce();
		looprate.sleep();
	}

	cv::destroyAllWindows();

	return 0;
}
