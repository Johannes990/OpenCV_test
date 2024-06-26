#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_drawing_functions() {
	cv::Mat maskImg = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);

	cv::namedWindow("Mask", cv::WINDOW_NORMAL);

	int point1 = 100;
	int point2 = 150;
	int thickness = 1;
	cv::createTrackbar("Trackbar 1", "Mask", &point1, 200);
	cv::createTrackbar("Trackbar 2", "Mask", &point2, 200);

	while (true) {
		cv::rectangle(maskImg, cv::Point(point1, point1), cv::Point(point2, point2), cv::Scalar(255, 0, 0), thickness, cv::LINE_4);

		cv::imshow("Mask", maskImg);
		cv::waitKey(1);

		maskImg = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
	}
}