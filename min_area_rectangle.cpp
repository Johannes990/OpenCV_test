#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_min_area_rect() {
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
	
	// draw the minimum area bounding boxes for all contours
	for (std::vector<cv::Point> contour : contours) {
		cv::RotatedRect contourMinAreaRect = cv::minAreaRect(contour);
		cv::Mat outputPoints;
		cv::boxPoints(contourMinAreaRect, outputPoints);

		float p1_x = outputPoints.at<float>(cv::Point(0, 0));
		float p1_y = outputPoints.at<float>(cv::Point(1, 0));
		float p2_x = outputPoints.at<float>(cv::Point(0, 1));
		float p2_y = outputPoints.at<float>(cv::Point(1, 1));
		float p3_x = outputPoints.at<float>(cv::Point(0, 2));
		float p3_y = outputPoints.at<float>(cv::Point(1, 2));
		float p4_x = outputPoints.at<float>(cv::Point(0, 3));
		float p4_y = outputPoints.at<float>(cv::Point(1, 3));

		cv::line(out, cv::Point(p1_x, p1_y), cv::Point(p2_x, p2_y), cv::Scalar(0, 75, 200), 1);
		cv::line(out, cv::Point(p2_x, p2_y), cv::Point(p3_x, p3_y), cv::Scalar(0, 75, 200), 1);
		cv::line(out, cv::Point(p3_x, p3_y), cv::Point(p4_x, p4_y), cv::Scalar(0, 75, 200), 1);
		cv::line(out, cv::Point(p4_x, p4_y), cv::Point(p1_x, p1_y), cv::Scalar(0, 75, 200), 1);
	}

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}