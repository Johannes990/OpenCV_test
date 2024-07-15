#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void draw_rotated_rectangle(cv::Mat& img, cv::RotatedRect rotatedRect, cv::Scalar& color, int thickness) {
	cv::Mat rectPoints;

	cv::boxPoints(rotatedRect, rectPoints);

	float p1_x = rectPoints.at<float>(cv::Point(0, 0));
	float p1_y = rectPoints.at<float>(cv::Point(1, 0));
	float p2_x = rectPoints.at<float>(cv::Point(0, 1));
	float p2_y = rectPoints.at<float>(cv::Point(1, 1));
	float p3_x = rectPoints.at<float>(cv::Point(0, 2));
	float p3_y = rectPoints.at<float>(cv::Point(1, 2));
	float p4_x = rectPoints.at<float>(cv::Point(0, 3));
	float p4_y = rectPoints.at<float>(cv::Point(1, 3));

	cv::Point p1 = cv::Point(p1_x, p1_y);
	cv::Point p2 = cv::Point(p2_x, p2_y);
	cv::Point p3 = cv::Point(p3_x, p3_y);
	cv::Point p4 = cv::Point(p4_x, p4_y);

	cv::line(img, p1, p2, color, thickness);
	cv::line(img, p2, p3, color, thickness);
	cv::line(img, p3, p4, color, thickness);
	cv::line(img, p4, p1, color, thickness);
}


void draw_vector_points_as_circles(cv::Mat& img, std::vector<cv::Point> points, cv::Scalar& color, int radius, int thickness) {
	for (int i = 0; i < points.size(); i++) {
		cv::circle(img, points[i], radius, color, thickness);
	}
}


void run_rotated_rect_intersect() {
	cv::Mat base = cv::Mat::zeros(cv::Size(1000, 800), CV_8UC3);
	cv::Scalar rectColor = cv::Scalar(83, 59, 199);
	int rectThickness = 2;
	std::vector<cv::Point> intersection1Points;
	std::vector<cv::Point> intersection2Points;
	int circleRadius = 5;
	int circleThickness = 2;
	cv::Scalar circleColor = cv::Scalar(0, 229, 255);
	std::vector<std::vector<cv::Point>> polyPoints1;
	std::vector<std::vector<cv::Point>> polyPoints2;
	cv::Scalar polyFillColor = cv::Scalar(200, 200, 0);
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
	cv::Size r4_size = cv::Size(650, 400);
	float r4_angle = 110.0;
	
	cv::RotatedRect r1(r1_center, r1_size, r1_angle);
	cv::RotatedRect r2(r2_center, r2_size, r2_angle);
	cv::RotatedRect r3(r3_center, r3_size, r3_angle);
	cv::RotatedRect r4(r4_center, r4_size, r4_angle);

	draw_rotated_rectangle(base, r1, rectColor, rectThickness);
	draw_rotated_rectangle(base, r2, rectColor, rectThickness);
	draw_rotated_rectangle(base, r3, rectColor, rectThickness);
	draw_rotated_rectangle(base, r4, rectColor, rectThickness);

	cv::rotatedRectangleIntersection(r1, r2, intersection1Points);
	cv::rotatedRectangleIntersection(r3, r4, intersection2Points);

	polyPoints1.push_back(intersection1Points);
	polyPoints2.push_back(intersection2Points);

	cv::fillPoly(base, polyPoints1, polyFillColor);
	cv::fillPoly(base, polyPoints2, polyFillColor);

	draw_vector_points_as_circles(base, intersection1Points, circleColor, circleRadius, circleThickness);
	draw_vector_points_as_circles(base, intersection2Points, circleColor, circleRadius, circleThickness);

	cv::namedWindow("Base picture", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Base picture", base);

	cv::waitKey(0);
}