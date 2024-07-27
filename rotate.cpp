#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_rotate() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat rotatedImg;

	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::namedWindow("Rotated", cv::WINDOW_NORMAL);

	cv::rotate(img, rotatedImg, cv::ROTATE_90_COUNTERCLOCKWISE);

	cv::imshow("Original", img);
	cv::imshow("Rotated", rotatedImg);

	cv::waitKey(0);

}