#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_magnitude() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat randImg = cv::Mat::zeros(img.size(), img.type());
	cv::Mat imgFloat, randImgFloat;
	cv::Mat magnitude = cv::Mat::zeros(img.size(), CV_32F);

	cv::namedWindow("In1", cv::WINDOW_NORMAL);
	cv::namedWindow("In2", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	img.convertTo(imgFloat, CV_32F);
	cv::randn(randImg, 10, 5);
	randImg.convertTo(randImgFloat, CV_32F);
	cv::magnitude(imgFloat, randImgFloat, magnitude);


	cv::imshow("In1", img);
	cv::imshow("In2", randImg);
	cv::imshow("Out", magnitude);

	cv::waitKey(0);
}