#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_pow() {
	cv::Mat smallMat = cv::Mat::zeros(4, 4, CV_8UC1);
	cv::Mat smallMatOut;
	smallMat.at<uchar>(cv::Point(0, 0)) = 2;
	smallMat.at<uchar>(cv::Point(1, 0)) = 3;
	smallMat.at<uchar>(cv::Point(2, 0)) = 4;
	smallMat.at<uchar>(cv::Point(3, 1)) = 5;
	smallMat.at<uchar>(cv::Point(1, 1)) = 6;

	// second parameter is the power level
	cv::pow(smallMat, 3, smallMatOut);

	cv::namedWindow("Matrix", cv::WINDOW_NORMAL);

	cv::imshow("Matrix", smallMatOut);

	std::cout << smallMat << std::endl;
	std::cout << smallMatOut << std::endl;

	cv::waitKey(0);
}