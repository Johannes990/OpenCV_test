#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_bounding_rect() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -2, cv::Scalar::all(255), 1);

	// draw all the bounding boxes for found contours
	for (std::vector<cv::Point> contour : contours) {
		cv::Rect contourBoundingBox = cv::boundingRect(contour);
		cv::rectangle(out, contourBoundingBox, cv::Scalar(150, 0, 180), 1);
	}

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);
	
	cv::waitKey(0);
}