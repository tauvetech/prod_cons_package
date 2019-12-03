#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "producteur");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int32>("chatter", 1000);
  ros::Rate loop_rate(1);
  std_msgs::Int32 val;

  while (ros::ok())
  {
    val.data++;
    chatter_pub.publish(val);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
