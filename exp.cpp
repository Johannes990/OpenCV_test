#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_exp() {
	cv::Mat matIn = cv::Mat::zeros(3, 3, CV_32FC1);
	cv::Mat matOut = cv::Mat::zeros(3, 3, CV_32FC1);

	matIn.at<float>(cv::Point(1, 0)) = 5.5;
	matIn.at<float>(cv::Point(2, 0)) = 1.0;
	matIn.at<float>(cv::Point(1, 2)) = 0.5;
	matIn.at<float>(cv::Point(2, 2)) = 1.33333;
	matIn.at<float>(cv::Point(0, 2)) = 0.21717;

	cv::exp(matIn, matOut);

	std::cout << matIn << std::endl;
	std::cout << matOut << std::endl;
}