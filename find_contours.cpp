#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_find_contours() {
	// findContours takes a single channel binary (non-zero pixel treated as 1) image as an input
	cv::Mat input = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat binaryImg;
	cv::Point offset;
	const int mode = cv::RETR_EXTERNAL; // this mode retrieves all the ectreme outer contours for all contours
	const int method = cv::CHAIN_APPROX_SIMPLE; // compresses horizontal, vertical and diagonal segments
												// and leaves only their endpoints

	cv::threshold(input, binaryImg, 100, 255, cv::THRESH_BINARY);

	cv::namedWindow("Input", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Binary", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Input", input);
	cv::imshow("Binary", binaryImg);
	
	cv::waitKey(0);
}