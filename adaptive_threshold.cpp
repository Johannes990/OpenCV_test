#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_adaptive_threshold() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat outputImg;

	cv::namedWindow("input", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Sample matrix", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Output", cv::WINDOW_GUI_NORMAL);

	cv::Mat sampleMat(cv::Size(5, 5), CV_8UC1);

	sampleMat.at<uchar>(cv::Point(0, 0)) = 122;
	sampleMat.at<uchar>(cv::Point(0, 1)) = 80;
	sampleMat.at<uchar>(cv::Point(0, 2)) = 30;
	sampleMat.at<uchar>(cv::Point(0, 3)) = 30;
	sampleMat.at<uchar>(cv::Point(0, 4)) = 30;
	sampleMat.at<uchar>(cv::Point(1, 0)) = 250;
	sampleMat.at<uchar>(cv::Point(1, 1)) = 34;
	sampleMat.at<uchar>(cv::Point(1, 2)) = 25;
	sampleMat.at<uchar>(cv::Point(1, 3)) = 25;
	sampleMat.at<uchar>(cv::Point(1, 4)) = 25;
	sampleMat.at<uchar>(cv::Point(2, 0)) = 100;
	sampleMat.at<uchar>(cv::Point(2, 1)) = 190;
	sampleMat.at<uchar>(cv::Point(2, 2)) = 220;
	sampleMat.at<uchar>(cv::Point(2, 3)) = 80;
	sampleMat.at<uchar>(cv::Point(2, 4)) = 80;
	sampleMat.at<uchar>(cv::Point(3, 0)) = 100;
	sampleMat.at<uchar>(cv::Point(3, 1)) = 190;
	sampleMat.at<uchar>(cv::Point(3, 2)) = 220;
	sampleMat.at<uchar>(cv::Point(3, 3)) = 140;
	sampleMat.at<uchar>(cv::Point(3, 4)) = 80;
	sampleMat.at<uchar>(cv::Point(4, 0)) = 100;
	sampleMat.at<uchar>(cv::Point(4, 1)) = 190;
	sampleMat.at<uchar>(cv::Point(4, 2)) = 255;
	sampleMat.at<uchar>(cv::Point(4, 3)) = 255;
	sampleMat.at<uchar>(cv::Point(4, 4)) = 194;

	cv::adaptiveThreshold(inputImg, outputImg, 100, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 5, -10);

	cv::imshow("input", inputImg);
	cv::imshow("Output", outputImg);

	cv::waitKey(0);
}