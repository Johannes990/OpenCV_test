#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mix_channels() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg", cv::IMREAD_COLOR);
	cv::Mat outRed = cv::Mat::zeros(img.size(), img.type());
	cv::Mat outGreen = cv::Mat::zeros(img.size(), img.type());
	cv::Mat outBlue = cv::Mat::zeros(img.size(), img.type());
	const std::vector<int> idxToIdxRed = { 2, 2 };
	const std::vector<int> idxToIdxGreen = { 1, 1 };
	const std::vector<int> idxToIdxBlue = { 0, 0 };

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("OutRed", cv::WINDOW_NORMAL);
	cv::namedWindow("OutGreen", cv::WINDOW_NORMAL);
	cv::namedWindow("OutBlue", cv::WINDOW_NORMAL);

	cv::mixChannels(img, outRed, idxToIdxRed);
	cv::mixChannels(img, outGreen, idxToIdxGreen);
	cv::mixChannels(img, outBlue, idxToIdxBlue);

	cv::imshow("In", img);
	cv::imshow("OutRed", outRed);
	cv::imshow("OutGreen", outGreen);
	cv::imshow("OutBlue", outBlue);

	cv::waitKey(0);
}