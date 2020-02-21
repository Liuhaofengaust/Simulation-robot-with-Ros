/**
 * 该例程设置/读取海龟例程中的参数
 */
 # include<string>
 # include<ros/ros.h>
 # include<std_srvs/Empty.h>

 int main(int argc, char **argv)
 {
     int red, green, blue;

    // ROS节点初始化,前两个参数不变，最后为发布者名称
     ros::init(argc, argv, "person_publisher");

     // 创建节点句柄
     ros::NodeHandle node;

     // 读取背景颜色参数
     ros::param::get("/background_r", red);
     ros::param::get("/background_g", green);
     ros::param::get("/background_b", blue);

     ROS_INFO("Get Background Color[%d, %d, %d]", red, green, blue);
     
     //设置背景颜色参数
     ros::param::set("/background_r", 255);
     ros::param::set("/background_g", 255);
     ros::param::set("/background_b", 255);

     ROS_INFO("Set Background Color[%d, %d, %d]", 255, 255, 255);

     //调用服务，刷新背景颜色
     ros::service::waitForService("/clear");
     ros::ServiceClient clear_background = node.serviceClient<std_srvs::Empty>("/clear");
     std_srvs::Empty srv;
     clear_background.call(srv);

     sleep(1);

     return 0;
 }

