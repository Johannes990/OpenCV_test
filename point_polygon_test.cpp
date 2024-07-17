#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_point_polygon_test() {
	cv::Mat img = cv::Mat::zeros(cv::Size(600, 600), CV_8UC1);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::rectangle(img, cv::Point(100, 100), cv::Point(300, 300), cv::Scalar(200, 200, 30), 2);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	cv::namedWindow("picture", cv::WINDOW_GUI_NORMAL);

	cv::imshow("picture", img);

	cv::waitKey(0);
}