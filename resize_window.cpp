#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_resize_window() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	const int win1Width1 = 150;
	const int win1Width2 = 800;
	const int win2Width1 = 700;
	const int win1Height1 = 900;
	const int win1Height2 = 200;
	const int win2Height1 = 1000;
	const int win2Height2 = 333;

	cv::namedWindow("Window1", cv::WINDOW_NORMAL);
	cv::namedWindow("Window2", cv::WINDOW_NORMAL);

	cv::imshow("Window1", img);
	cv::imshow("Window2", img);

	cv::waitKey(0);
	cv::resizeWindow("Window1", win1Width1, win1Height1);

	cv::waitKey(0);
	cv::resizeWindow("Window2", win2Width1, win2Height1);

	cv::waitKey(0);
	cv::resizeWindow("Window1", win1Width2, win1Height2);

	cv::waitKey(0);
	cv::resizeWindow("Window2", win2Width1, win2Height2);

	cv::waitKey(0);
}