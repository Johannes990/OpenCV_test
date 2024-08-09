#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_fit_ellipse() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_COLOR);
	cv::Mat out = cv::Mat::zeros(img.size(), img.type());
	cv::Mat grayImg;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	cv::threshold(grayImg, grayImg, 100, 255, cv::THRESH_BINARY);
	cv::findContours(grayImg, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, cv::Scalar(0, 150, 250), 1);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}