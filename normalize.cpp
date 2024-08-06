#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_normalize() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat normalized, hsvImg, blurImg;
	cv::Mat greenMask = cv::Mat::zeros(img.size(), CV_8U);
	cv::Scalar greenFilterFrom = cv::Scalar(30, 0, 0);
	cv::Scalar greenFilterTo = cv::Scalar(103, 255, 255);
	double alpha = 255;
	double beta = 255.0;
	int normType = cv::NORM_MINMAX;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);
	cv::namedWindow("mask", cv::WINDOW_NORMAL);

	// next three lines to blur image, and then get the mask from green regions
	cv::GaussianBlur(img, blurImg, cv::Size(7, 7), 25);
	cv::cvtColor(blurImg, hsvImg, cv::COLOR_BGR2HSV);
	cv::inRange(hsvImg, greenFilterFrom, greenFilterTo, greenMask);

	// split image into channels
	std::vector<cv::Mat> channels;
	cv::split(img, channels);

	// normalize image channel by channel
	for (int i = 0; i < channels.size(); i++) {
		cv::normalize(channels[i], channels[i], alpha, beta, normType, -1, greenMask);
	}

	// merge channels together again
	cv::merge(channels, normalized);

	cv::imshow("In", img);
	cv::imshow("Out", normalized);
	cv::imshow("mask", greenMask);

	cv::waitKey(0);
}