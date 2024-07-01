#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_integral() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat summationResult, squareSumResult, tiltedResult;

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Summation result", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Squared summation result", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Tilted result", cv::WINDOW_GUI_NORMAL);

	cv::integral(inputImg, summationResult, squareSumResult, tiltedResult, CV_32F);

	cv::imshow("Original image", inputImg);
	cv::imshow("Summation result", summationResult);
	cv::imshow("Squared summation result", squareSumResult);
	cv::imshow("Tilted result", tiltedResult);

	cv::waitKey(0);
}