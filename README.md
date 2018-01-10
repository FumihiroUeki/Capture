# Capture  
ROS と opencvを使用して青色の物体の検出をするものです。  
BGR画像をHSV画像に変換し,2値化します。  
# How to use  
$cd catkin_ws/src  
$git clone https://github.com/FumihiroUeki/Capture.git  
$cd ../  
$catkin_make  
$roscore  
$rosrun Capture talker  
$rosrun Capture listener
