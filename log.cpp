#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_log() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_COLOR);
	cv::Mat log;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Log", cv::WINDOW_NORMAL);

	cv::log(img, log);

	cv::imshow("In", img);
	cv::imshow("Log", log);

	cv::waitKey(0);
}