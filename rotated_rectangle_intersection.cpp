#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_rotated_rect_intersect() {
	cv::Mat base = cv::Mat::zeros(cv::Size(1000, 800), CV_8UC3);
	cv::Scalar rectColor = cv::Scalar(83, 59, 199);
	cv::Point2f r1_center = cv::Point2f(300, 300);
	cv::Size r1_size = cv::Size(100, 100);
	float r1_angle = 0.0;
	cv::Point2f r2_center = cv::Point2f(340, 300);
	cv::Size r2_size = cv::Size(100, 100);
	float r2_angle = 0.0;
	cv::Point2f r3_center = cv::Point2f(640, 300);
	cv::Size r3_size = cv::Size(250, 250);
	float r3_angle = 45.0;
	cv::Point2f r4_center = cv::Point2f(500, 700);
	cv::Size r4_size = cv::Size(400, 400);
	float r4_angle = 110.0;
	
	cv::RotatedRect r1(r1_center, r1_size, r1_angle);
	cv::RotatedRect r2(r2_center, r2_size, r2_angle);
	cv::RotatedRect r3(r3_center, r3_size, r3_angle);
	cv::RotatedRect r4(r4_center, r4_size, r4_angle);

	cv::namedWindow("Base picture", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Base picture", base);

	cv::waitKey(0);
}