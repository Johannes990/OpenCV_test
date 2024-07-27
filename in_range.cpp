#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_in_range() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat filteredOutput;
	cv::Scalar lowerThreshold = cv::Scalar(100, 80, 120);
	cv::Scalar upperThreshold = cv::Scalar(150, 190, 150);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Filtered image", cv::WINDOW_NORMAL);

	cv::inRange(img, lowerThreshold, upperThreshold, filteredOutput);

	cv::imshow("In", img);
	cv::imshow("Filtered image", filteredOutput);

	cv::waitKey(0);
}