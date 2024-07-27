#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_flip() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat flipHorizontal, flipVertical, flipBoth;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Horizontal flip", cv::WINDOW_NORMAL);
	cv::namedWindow("Vertical flip", cv::WINDOW_NORMAL);
	cv::namedWindow("Both flip", cv::WINDOW_NORMAL);

	// oddly, no cv enumerators here to specify flip type
	// 1 - horizontal flip
	// 0 - vertical flip
	// -1 - flip in both axes
	cv::flip(img, flipHorizontal, 1);
	cv::flip(img, flipVertical, 0);
	cv::flip(img, flipBoth, -1);

	cv::imshow("In", img);
	cv::imshow("Horizontal flip", flipHorizontal);
	cv::imshow("Vertical flip", flipVertical);
	cv::imshow("Both flip", flipBoth);
	cv::waitKey(0);
}