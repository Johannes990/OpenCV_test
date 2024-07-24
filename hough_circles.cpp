#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_hough_circles() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\rims.jpeg", cv::IMREAD_COLOR);
	cv::Mat out = img.clone();
	cv::Mat circles;
	const int minDistance = 8;

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	cv::HoughCircles(img, circles, cv::HOUGH_GRADIENT_ALT, 1.5, minDistance, 100, 0.8, 2, 150);

	std::cout << circles.size() << std::endl;

	for (int i = 0; i < circles.cols; i++) {
		int x = circles.at<cv::Vec3f>(cv::Point(i, 0))[0];
		int y = circles.at<cv::Vec3f>(cv::Point(i, 0))[1];
		int radius = circles.at<cv::Vec3f>(cv::Point(i, 0))[2];

		cv::circle(out, cv::Point(x, y), radius, cv::Scalar(100, 200, 0), cv::FILLED);
	}

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKeyEx(0);
}