#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_divide() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\moll.png", cv::IMREAD_COLOR);
	cv::Mat smallMat1 = cv::Mat::zeros(4, 4, CV_8UC1);
	cv::Mat smallMat2 = cv::Mat::zeros(4, 4, CV_8UC1);
	cv::Mat twoArrayDivideOut, imgDivideOut;

	smallMat1.at<uchar>(cv::Point(0, 1)) = 100;
	smallMat1.at<uchar>(cv::Point(1, 1)) = 100;
	smallMat1.at<uchar>(cv::Point(2, 1)) = 100;
	smallMat1.at<uchar>(cv::Point(0, 2)) = 125;
	smallMat1.at<uchar>(cv::Point(0, 3)) = 150;
	smallMat1.at<uchar>(cv::Point(1, 3)) = 150;

	smallMat2.at<uchar>(cv::Point(0, 1)) = 2;
	smallMat2.at<uchar>(cv::Point(1, 1)) = 2;
	smallMat2.at<uchar>(cv::Point(2, 1)) = 4;
	smallMat2.at<uchar>(cv::Point(0, 2)) = 5;
	smallMat2.at<uchar>(cv::Point(0, 3)) = 5;
	smallMat2.at<uchar>(cv::Point(1, 3)) = 1;

	cv::namedWindow("SmallMat", cv::WINDOW_NORMAL);
	cv::namedWindow("twoArrayDivideOut", cv::WINDOW_NORMAL);

	cv::divide(smallMat1, smallMat2, twoArrayDivideOut);

	std::cout << twoArrayDivideOut << std::endl;

	cv::imshow("SmallMat", smallMat1);
	cv::imshow("twoArrayDivideOut", twoArrayDivideOut);

	cv::waitKey(0);
}