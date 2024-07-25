#include <opencv2/opencv.hpp>
#include "opencv_test.h"


// do some stuff with mouse events
void mouse_event_callback(int mouseEvent, int x, int y, int flags, void* userData) {
	switch (mouseEvent) {
	case cv::EVENT_MOUSEMOVE:
		std::cout << "Mouse moved to coordinates x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_LBUTTONDOWN:
		std::cout << "Mouse left button pressed at x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_RBUTTONDOWN:
		std::cout << "Mouse right button pressed at x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_LBUTTONUP:
		std::cout << "Mouse left button released at x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_RBUTTONUP:
		std::cout << "Mouse right button released at x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_LBUTTONDBLCLK:
		std::cout << "Mouse left button double-clicked at x: " << x << ", y: " << y << std::endl;
		break;
	case cv::EVENT_RBUTTONDBLCLK:
		std::cout << "Mouse right button double-clicked at x: " << x << ", y: " << y << std::endl;
		break;
	}
}

void run_set_mouse_callback() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	
	cv::namedWindow("Window", cv::WINDOW_NORMAL);

	cv::setMouseCallback("Window", mouse_event_callback, NULL);

	cv::imshow("Window", img);

	cv::waitKey(0);
}