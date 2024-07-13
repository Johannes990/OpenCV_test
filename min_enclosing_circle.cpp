#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_min_enclosing_circle() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -2, cv::Scalar::all(255), 1);
	
	cv::Point2f center;
	float radius;

	// draw the minimum enclosing circle for each contour fooud
	for (std::vector<cv::Point> contour : contours) {
		cv::minEnclosingCircle(contour, center, radius);
		cv::circle(out, center, radius, cv::Scalar(0, 200, 255), 1);
	}

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}