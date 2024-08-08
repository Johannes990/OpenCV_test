#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_magnitude() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat randImg = cv::Mat::zeros(img.size(), img.type());
	cv::randn(randImg, 60, 10);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", randImg);

	cv::waitKey(0);
}