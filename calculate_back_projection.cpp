#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_calculate_back_project() {
	const int histSize = 256;
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pilt.JPG");

	//cv::cvtColor(img, img, cv::COLOR_BGR2HSV);

	cv::namedWindow("Back projection", 0);
	cv::namedWindow("Input", 0);
	cv::imshow("Input", img);

	float range[] = { 0, 255 };
	const float* histRange = { range };
	cv::Mat hist, backProjection;
	const int channelNum = 2;

	cv::calcHist(&img, 1, &channelNum, cv::Mat(), hist, 1, &histSize, &histRange, true, false);
	cv::normalize(hist, hist, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());
	cv::calcBackProject(&img, 1, &channelNum, hist, backProjection, &histRange, 1);

	cv::imshow("Back projection", backProjection);

	cv::waitKey(0);
}