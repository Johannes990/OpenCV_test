#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_repeat() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\moll.png", cv::IMREAD_COLOR);
	cv::Mat out;
	const int nX = 3;
	const int nY = 4;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("in", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}