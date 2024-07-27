#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_flip() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat flipHorizontal, flipVertical, flipBoth;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Horizontal flip", cv::WINDOW_NORMAL);
	cv::namedWindow("Vertical flip", cv::WINDOW_NORMAL);
	cv::namedWindow("Both flip", cv::WINDOW_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}