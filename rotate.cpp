#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_rotate() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat rotatedImg90, rotatedImg180, rotatedImg270;

	cv::namedWindow("Original", cv::WINDOW_NORMAL);
	cv::namedWindow("Rotated90", cv::WINDOW_NORMAL);
	cv::namedWindow("Rotated180", cv::WINDOW_NORMAL);
	cv::namedWindow("Rotated270", cv::WINDOW_NORMAL);

	// rotate using all 3 flags
	cv::rotate(img, rotatedImg90, cv::ROTATE_90_CLOCKWISE);
	cv::rotate(img, rotatedImg180, cv::ROTATE_180);
	cv::rotate(img, rotatedImg270, cv::ROTATE_90_COUNTERCLOCKWISE);

	cv::imshow("Original", img);
	cv::imshow("Rotated90", rotatedImg90);
	cv::imshow("Rotated180", rotatedImg180);
	cv::imshow("Rotated270", rotatedImg270);

	cv::waitKey(0);

}