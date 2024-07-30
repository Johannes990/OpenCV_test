#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_transpose() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat transposed;

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}