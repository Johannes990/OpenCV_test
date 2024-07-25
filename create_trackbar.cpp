#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_create_trackbar() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	const std::string trackbarName = "Control 1";
	int trackbarValue = 0;
	int trackbarMaxValue = 100;

	cv::namedWindow("Window", cv::WINDOW_FREERATIO);

	cv::createTrackbar(trackbarName, "Window", &trackbarValue, trackbarMaxValue);

	cv::imshow("Window", img);

	cv::waitKey(0);
}