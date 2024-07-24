#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_hough_circles() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	cv::Mat out = img.clone();

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKeyEx(0);
}