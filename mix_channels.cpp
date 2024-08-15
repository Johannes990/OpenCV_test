#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mix_channels() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg", cv::IMREAD_COLOR);
	cv::Mat out = cv::Mat::zeros(img.size(), img.type());
	std::vector<int> idxToIdx = { 0, 1, 1, 2, 2, 0 };

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::mixChannels(img, out, idxToIdx);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}