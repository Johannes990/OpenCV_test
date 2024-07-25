#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void handle_mouse_move(int x, int y) {
	std::cout << "Mouse moved to coordinates x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_left_button_down(int x, int y) {
	std::cout << "Mouse left button pressed at x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_right_button_down(int x, int y) {
	std::cout << "Mouse right button pressed at x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_left_button_up(int x, int y) {
	std::cout << "Mouse left button released at x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_right_button_up(int x, int y) {
	std::cout << "Mouse right button released at x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_left_double_click(int x, int y) {
	std::cout << "Mouse left button double-clicked at x: " << x << ", y: " << y << std::endl;
}

void handle_mouse_right_double_click(int x, int y) {
	std::cout << "Mouse right button double-clicked at x: " << x << ", y: " << y << std::endl;
}

// do some stuff with mouse events
void mouse_event_callback(int mouseEvent, int x, int y, int flags, void* userData) {
	switch (mouseEvent) {
	case cv::EVENT_MOUSEMOVE:
		handle_mouse_move(x, y);
		break;
	case cv::EVENT_LBUTTONDOWN:
		handle_mouse_left_button_down(x, y);
		break;
	case cv::EVENT_RBUTTONDOWN:
		handle_mouse_right_button_down(x, y);
		break;
	case cv::EVENT_LBUTTONUP:
		handle_mouse_left_button_up(x, y);
		break;
	case cv::EVENT_RBUTTONUP:
		handle_mouse_right_button_up(x, y);
		break;
	case cv::EVENT_LBUTTONDBLCLK:
		handle_mouse_left_double_click(x, y);
		break;
	case cv::EVENT_RBUTTONDBLCLK:
		handle_mouse_right_double_click(x, y);
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