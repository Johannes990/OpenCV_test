#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_min_enclosing_triangle() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, cv::Scalar(0, 150, 250), 1);

	// draw the minimum bounding triangle for each contour
	for (int i = 0; i < contours.size(); i++) {
		std::vector<cv::Point> vertices;
		cv::minEnclosingTriangle(contours[i], vertices);

		cv::line(out, vertices[0], vertices[1], cv::Scalar(190, 170, 0), 1);
		cv::line(out, vertices[1], vertices[2], cv::Scalar(190, 170, 0), 1);
		cv::line(out, vertices[2], vertices[0], cv::Scalar(190, 170, 0), 1);
	}

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}