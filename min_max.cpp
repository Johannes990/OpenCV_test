#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_min_max() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_8UC1);
	cv::Mat mat2 = cv::Mat::zeros(3, 3, CV_8UC1);
	cv::Mat maxOut, minOut;

	mat1.at<uchar>(cv::Point(1, 0)) = 50;
	mat1.at<uchar>(cv::Point(1, 1)) = 100;
	mat1.at<uchar>(cv::Point(0, 0)) = 200;
	mat1.at<uchar>(cv::Point(0, 1)) = 160;

	mat2.at<uchar>(cv::Point(1, 0)) = 40;
	mat2.at<uchar>(cv::Point(1, 1)) = 150;
	mat2.at<uchar>(cv::Point(0, 0)) = 20;
	mat2.at<uchar>(cv::Point(0, 1)) = 160;

	cv::namedWindow("mat1", cv::WINDOW_NORMAL);
	cv::namedWindow("mat2", cv::WINDOW_NORMAL);

	cv::imshow("mat1", mat1);
	cv::imshow("mat2", mat2);

	cv::waitKey(0);

	cv::namedWindow("max", cv::WINDOW_NORMAL);
	cv::namedWindow("min", cv::WINDOW_NORMAL);

	cv::min(mat1, mat2, minOut);
	cv::max(mat1, mat2, maxOut);

	cv::imshow("min", minOut);
	cv::imshow("max", maxOut);

	cv::waitKey(0);
}