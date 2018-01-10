#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/opencv.hpp>

cv::Mat image;
cv::Mat hsv;
cv::Mat dst;

void Callback(const sensor_msgs::ImageConstPtr &msg)
{
	try{
		image = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
	}	
	catch(cv_bridge::Exception &e){
		ROS_ERROR("cv_bridge exception : %s", e.what());
	}	

	cv::cvtColor(image, hsv, CV_BGR2HSV);
	cv::inRange(hsv, cv::Scalar(110, 50, 50), cv::Scalar(130, 255, 255), dst);

	cv::imshow("capture", image);
	cv::imshow("threshold", dst);
	cv::waitKey(1);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	ros::NodeHandle nh("~");
	
	image_transport::ImageTransport it(nh);
	image_transport::Subscriber image_sub = it.subscribe("/talker/image", 10, Callback);
	ros::spin();

	return 0;
}
