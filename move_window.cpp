#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_move_window() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	const int x = 1500;
	const int y = 500;

	cv::namedWindow("Window", cv::WINDOW_NORMAL);

	cv::imshow("Window", img);

	cv::moveWindow("Window", x, y);
	cv::waitKey(0);

	// shift window position after keystroke
	cv::moveWindow("Window", x + 300, y + 300);
	cv::waitKey(0);
}