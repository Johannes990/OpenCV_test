#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_threshold() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat outputImg;

	cv::namedWindow("input", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Sample matrix", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Output", cv::WINDOW_GUI_NORMAL);

	cv::Mat sampleMat(cv::Size(3, 3), CV_8UC1);

	sampleMat.at<uchar>(cv::Point(0, 0)) = 122;
	sampleMat.at<uchar>(cv::Point(0, 1)) = 80;
	sampleMat.at<uchar>(cv::Point(0, 2)) = 30;
	sampleMat.at<uchar>(cv::Point(1, 0)) = 250;
	sampleMat.at<uchar>(cv::Point(1, 1)) = 34;
	sampleMat.at<uchar>(cv::Point(1, 2)) = 25;
	sampleMat.at<uchar>(cv::Point(2, 0)) = 100;
	sampleMat.at<uchar>(cv::Point(2, 1)) = 190;
	sampleMat.at<uchar>(cv::Point(2, 2)) = 220;

	cv::threshold(inputImg, outputImg, 99, 255, cv::THRESH_TOZERO_INV);

	cv::imshow("input", inputImg);
	cv::imshow("Sample matrix", sampleMat);
	cv::imshow("Output", outputImg);
	cv::waitKey(0);
}