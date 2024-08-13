#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mahalanobis() {
	std::srand(time(NULL));	// set a new random seed for rng
	
	cv::Mat input = cv::Mat::zeros(500, 500, CV_8UC3);
	const std::vector<cv::Point> pointsGroup1 = {cv::Point(86, 5), cv::Point(112, 270),
										   cv::Point(370, 109), cv::Point(37, 380),
										   cv::Point(200, 100), cv::Point(12, 400),
										   cv::Point(400, 200), cv::Point(400, 400)};
	const std::vector<cv::Point> pointsGroup2 = {cv::Point(42, 376), cv::Point(495, 54),
										   cv::Point(345, 53), cv::Point(58, 480),
										   cv::Point(132, 183), cv::Point(107, 86),
										   cv::Point(100, 175), cv::Point(80, 31)};
	const cv::Scalar point1Color = cv::Scalar(25, 190, 190);
	const cv::Scalar point2Color = cv::Scalar(230, 0, 76);
	const int radius = 4;
	cv::Mat group1, mean1, covar1, group2, mean2, covar2;

	cv::namedWindow("points", cv::WINDOW_NORMAL);

	for (int i = 0; i < pointsGroup1.size(); i++) {
		cv::circle(input, pointsGroup1[i], radius, point1Color, cv::FILLED);
	}

	for (int i = 0; i < pointsGroup2.size(); i++) {
		cv::circle(input, pointsGroup2[i], radius, point2Color, cv::FILLED);
	}

	cv::imshow("points", input);

	cv::waitKey(0);
}