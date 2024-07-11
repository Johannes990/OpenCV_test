#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_emd() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan3.jpg", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);

	int histSize = 256;
	cv::Mat histOut1, histOut2;
	float range[] = { 0, 255 };
	const float* histRange[] = { range };
	const int channelNum = 2; // here we are summing the red channel

	cv::calcHist(&img1, 1, &channelNum, cv::Mat(), histOut1, 1, &histSize, histRange, true, false);
	cv::calcHist(&img2, 1, &channelNum, cv::Mat(), histOut2, 1, &histSize, histRange, true, false);

	// creating signature steps
	cv::Mat temp1(cv::Size(3, 256), CV_32FC1);
	cv::Mat temp2(cv::Size(3, 256), CV_32FC1);

	for (int i = 0; i < histSize; i++) {
		temp1.at<float>(i, 0) = histOut1.at<float>(i, 0);
		temp1.at<float>(i, 1) = (float)0;
		temp1.at<float>(i, 2) = (float)i;

		temp2.at<float>(i, 0) = histOut2.at<float>(i, 0);
		temp2.at<float>(i, 1) = (float)0;
		temp2.at<float>(i, 2) = (float)i;
	}

	// get the EMD result
	std::cout << std::to_string(cv::EMD(temp1, temp2, cv::DIST_L1)) << std::endl;
}