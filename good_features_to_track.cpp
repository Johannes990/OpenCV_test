#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_good_features_to_track() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	cv::Mat out = img.clone();
	cv::Mat corners;
	const int maxCorners = 30;
	const double qualityLevel = 0.001;
	const double minDistance = 100.0;
	const int blockSize = 4;
	const float k = 0.05;

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	// corners will hold type CV_32FC2 type elements after function call
	// 2 channels for both the x and y axis coordinates
	cv::goodFeaturesToTrack(img, corners, maxCorners, qualityLevel, minDistance);

	for (int i = 0; i < corners.rows; i++) {
		cv::Vec2f cPoint = corners.at<cv::Vec2f>(cv::Point(0, i));
		int xCoord = cPoint[0];
		int yCoord = cPoint[1];
		cv::Point center = cv::Point(xCoord, yCoord);
		cv::circle(out, center, 6, cv::Scalar(0, 90, 200), cv::FILLED);
	}

	cv::namedWindow("Image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Image", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}