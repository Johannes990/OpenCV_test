#include <iostream>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include "opencv_test.h"


void run_conv_filters() {
	cv::Mat custom = (cv::Mat_<float>(3, 3) << 1, 2, 50, 6, 8, 1, 0, 1, 2);
	cv::Mat kernel = (cv::Mat_<float>(2, 2) << 1, 0, 7, 1);
	cv::Mat gaussianKernel = (cv::Mat_<float>(3, 3) << 0.0625, 0.125, 0.0625, 0.125, 0.25, 0.125, 0.0625, 0.125, 0.0625); // 3x3 gaussian kernel

	cv::Mat custom2, kernel2, filter2D, filter2D2, gaussian, gaussian2;

	cv::filter2D(custom, filter2D, -1, gaussianKernel, cv::Point(-1, -1)); // here we are using the same kernel that would be used in a 3x3 gaussian

	cv::GaussianBlur(custom, gaussian, cv::Size(3, 3), 0);
	custom.convertTo(custom2, CV_8U);
	kernel.convertTo(kernel2, CV_8U);
	filter2D.convertTo(filter2D2, CV_8U);
	gaussian.convertTo(gaussian2, CV_8U);

	cv::namedWindow("Input", cv::WINDOW_NORMAL);
	cv::namedWindow("Kernel", cv::WINDOW_NORMAL);
	cv::namedWindow("filter 2D", cv::WINDOW_NORMAL);
	cv::namedWindow("Gaussian", cv::WINDOW_NORMAL);

	cv::imshow("Input", custom2);
	cv::imshow("Kernel", kernel2);
	cv::imshow("filter 2D", filter2D2);
	cv::imshow("Gaussian", gaussian2); //

	cv::waitKey(0);
}