#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_divide() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\moll.png", cv::IMREAD_COLOR);
	cv::Mat smallMat = cv::Mat::zeros(4, 4, CV_8UC1);

	smallMat.at<uchar>(cv::Point(0, 1)) = 100;
	smallMat.at<uchar>(cv::Point(1, 1)) = 100;
	smallMat.at<uchar>(cv::Point(2, 1)) = 100;
	smallMat.at<uchar>(cv::Point(0, 2)) = 100;
	smallMat.at<uchar>(cv::Point(0, 3)) = 100;
	smallMat.at<uchar>(cv::Point(1, 3)) = 100;

	cv::namedWindow("SmallMat", cv::WINDOW_NORMAL);

	cv::imshow("SmallMat", smallMat);

	cv::waitKey(0);
}