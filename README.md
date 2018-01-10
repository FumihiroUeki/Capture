# ros_opencv  
ROS と opencvを使用して青色の物体の検出をするものです。  
  
# How to use  
$cd catkin_ws  
$catkin_create_pkg Capture sensor_msgs cv_bridge roscpp rospy std_msgs image_transport  
$cd src    
$git clone https://github.com/FumihiroUeki/ros_opencv.git  
$cd ../  
$catkin_make  
$roscore  
$rosrun Capture talker  
$rosrun Capture listener
