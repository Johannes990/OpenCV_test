#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_log() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_COLOR);
	cv::Mat floatImg, uCharImg, expImage, log;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Log", cv::WINDOW_NORMAL);

	img.convertTo(floatImg, CV_32F);
	cv::log(floatImg, log);
	log.convertTo(uCharImg, CV_8UC3);
	
	/*
	* here we can see that img -> log -> exp: img
	* we get back the initial image
	* 
	* cv::exp(log, expImage);
	* expImage.convertTo(uCharImg, CV_8UC3);
	*/

	cv::imshow("In", img);
	cv::imshow("Log", uCharImg);

	cv::waitKey(0);
}