#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_contour_area() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	cv::Scalar contourColor = cv::Scalar(200, 255, 0);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	double area = 0.0;

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, contourColor, 1);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}