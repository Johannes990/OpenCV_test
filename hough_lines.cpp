#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_hough_lines() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	cv::Mat binary;
	cv::Mat lines;
	cv::Mat out = img.clone();
	const double rho = 1.0;
	const double theta = 1.0;
	const int threshold = 1.0;
	const double minLineLength = 20.0;
	const double maxLineGap = 25.0;

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	cv::threshold(img, binary, 100, 255, cv::THRESH_BINARY);

	cv::namedWindow("Img", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Img", img);
	cv::imshow("Out", binary);

	cv::waitKey(0);
}