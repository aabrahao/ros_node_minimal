# ros\_node\_minimal

**ros\_node\_minimal** is a simple ROS2 node that subsiscribe to **image\_raw** from **usb\_cam** node and display the video using a QWidget.

## ROS2 usage

``` cpp
int main(int argc, char *argv[]) {
    Ros ros(argc, argv, "node_name");

    auto node = Ros::instance()->node();
    auto image_subscriber = node->create_subscription<sensor_msgs::msg::Image>("image_raw", 10, imageCallback);
    
    ros.spin(); // or ros.spinOnBackground() for multithreading!
    return 0;
}
```

Anthony Abrahao <aabrahao@fiu.edu>
