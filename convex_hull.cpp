#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_convex_hull() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\points.jpg", cv::IMREAD_GRAYSCALE);
	std::vector<cv::Point> temp;
	std::vector<std::vector<cv::Point>> points;
	

	cv::threshold(img, img, 50, 255, cv::THRESH_BINARY);

	for (int i = 0; i < img.cols; i++) {
		for (int j = 0; j < img.rows; j++) {
			cv::Point p = cv::Point(i, j);

			if (img.at<uchar>(p) == 0) {
				temp.push_back(p);
			}
		}
	}

	points.push_back(temp);

	std::vector<std::vector<cv::Point>> convexHullOutput(points.size());

	cv::convexHull(points[0], convexHullOutput[0]);

	cv::drawContours(img, convexHullOutput, -1, cv::Scalar(100, 100, 50), 1);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}