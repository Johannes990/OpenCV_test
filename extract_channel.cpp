#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_extract_channel() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat channel;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Channel", cv::WINDOW_NORMAL);

	cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
	cv::extractChannel(img, channel, 2);

	cv::imshow("In", img);
	cv::imshow("Channel", channel);

	cv::waitKey(0);
}