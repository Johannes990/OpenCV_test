#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_complete_symm() {
	cv::Mat matrix = cv::Mat::zeros(4, 4, CV_8UC1);
	matrix.at<uchar>(cv::Point(1, 0)) = 150;
	matrix.at<uchar>(cv::Point(2, 0)) = 100;
	matrix.at<uchar>(cv::Point(3, 0)) = 90;
	matrix.at<uchar>(cv::Point(3, 1)) = 255;

	cv::namedWindow("Small", cv::WINDOW_NORMAL);
	cv::imshow("Small", matrix);

	cv::waitKey(0);

	// default value is for the upper right part to be copied into the lower left part
	// completeSymm(_, lowerToUpper = false) ...
	cv::completeSymm(matrix);

	cv::imshow("Small", matrix);

	cv::waitKey(0);
}