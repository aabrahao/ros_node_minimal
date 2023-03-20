#include "Ros.h"

void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg) { 
    LOG("Received Image: %s %dx%d", msg->encoding.c_str(), msg->width, msg->height);
    if (msg->encoding != "rgb8") {
        LOG("Image encoding not supported!");
        return;
    }
    // QImage image(&msg->data[0], msg->width, msg->height, QImage::Format_RGB888);
}

int main(int argc, char *argv[]) {
    Ros ros(argc, argv, "node_name");

    auto node = Ros::instance()->node();
    auto image_subscriber = node->create_subscription<sensor_msgs::msg::Image>("image_raw", 10, imageCallback);
    
    ros.spin(); // or ros.spinOnBackground() for multithreading!
    return 0;
}
