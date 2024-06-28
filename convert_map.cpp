#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_convert_maps() {
	cv::Mat _16sc2Mat = cv::Mat::zeros(cv::Size(5, 5), CV_32FC1);
	cv::Mat _16sc1Mat = cv::Mat::zeros(cv::Size(5, 5), CV_32FC1);
	cv::Mat out1 = cv::Mat::zeros(cv::Size(5, 5), CV_16UC1);	// this matrix will hold the rounded integer part of both of our input matrices
	cv::Mat out2 = cv::Mat::zeros(cv::Size(5, 5), CV_16SC2);	// this matrix will hold the decimal parts of both of our input matrices encoded somehow

	_16sc2Mat.at<float>(cv::Point(2, 4)) = 2.3;
	_16sc2Mat.at<float>(cv::Point(4, 4)) = 8.9;
	_16sc1Mat.at<float>(cv::Point(1, 3)) = 3.4;

	cv::convertMaps(_16sc1Mat, _16sc2Mat, out1, out2, CV_16SC2);

	std::cout << out1 << std::endl;
	std::cout << out2 << std::endl;
}