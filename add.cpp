#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_add() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat smallMat = cv::Mat::zeros(3, 3, CV_8UC1);
	cv::Mat smallAddOut, imgAddOut;
	cv::Scalar singleChannelAddend = cv::Scalar(50); // add 50 to a single channel
	cv::Scalar tripleChannelAddend = cv::Scalar(50, 50, 50); // add 50 to all three channels

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	cv::imshow("Img", img);

	// stdout print for small matrix
	std::cout << smallMat << std::endl;

	cv::add(smallMat, singleChannelAddend, smallAddOut);

	std::cout << smallAddOut << std::endl;

	cv::waitKey(0);

	// show image for a large matrix
	cv::add(img, tripleChannelAddend, imgAddOut);
	
	cv::namedWindow("added", cv::WINDOW_NORMAL);

	cv::imshow("added", imgAddOut);

	cv::waitKey(0);
}