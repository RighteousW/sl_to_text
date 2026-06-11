#include "video-capture.h"

#include <opencv2/opencv.hpp>

int run_camera_preview() {
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) {
        return 1;
    }

    const char* window_name = "SL to Text - Camera Preview";
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);

    cv::Mat frame;

    while (true) {
        camera >> frame;

        if (frame.empty()) {
            return 1;
        }

        cv::imshow(window_name, frame);

        int key = cv::waitKey(1);

        if (key == 27) {
            break;
        }

        if (cv::getWindowProperty(window_name, cv::WND_PROP_VISIBLE) < 1) {
            break;
        }
    }

    cv::destroyWindow(window_name);
    return 0;
}
