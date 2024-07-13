#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_arc_length() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -2, cv::Scalar::all(255), 1);

	cv::Point2f center;
	float radius;

	for (int i = 0; i < contours.size(); i++) {
		cv::minEnclosingCircle(contours[i], center, radius);
		double arcLength = cv::arcLength(contours[i], true);
		cv::putText(out, "length", center, 1, 1, cv::Scalar(100, 0, 200), 1);
		cv::putText(out, std::to_string(arcLength), cv::Point(center.x, center.y + 15), 1, 1, cv::Scalar(100, 0, 200), 1);
	}

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}