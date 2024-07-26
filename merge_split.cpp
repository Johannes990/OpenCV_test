#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_merge_split() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg", cv::IMREAD_COLOR);
	std::vector<cv::Mat> channels;
	cv::Mat singleChannel, mergedChannels;

	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::namedWindow("Single channel images", cv::WINDOW_NORMAL);
	cv::namedWindow("Merged channels", cv::WINDOW_NORMAL);

	cv::imshow("Original", img);

	cv::waitKey(0);

	cv::split(img, channels);

	for (int i = 0; i < channels.size(); i++) {
		singleChannel = channels[i];
		cv::imshow("Single channel images", singleChannel);
		cv::waitKey(0);
	}

	cv::waitKey(0);

	cv::merge(channels, mergedChannels);

	cv::imshow("Merged channels", mergedChannels);

	cv::waitKey(0);
}