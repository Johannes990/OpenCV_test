#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_count_non_zero() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat smallImg = cv::Mat::zeros(3, 3, CV_8UC1);

	// convert image to binary, to count non-zero elements
	cv::threshold(img, img, 140, 255, cv::THRESH_BINARY);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Small image", cv::WINDOW_NORMAL);

	std::cout << "Non-zero elements in array before assigning values: " << 
		cv::countNonZero(smallImg) << std::endl;

	smallImg.at<uchar>(cv::Point(1, 1)) = 100;
	smallImg.at<uchar>(cv::Point(1, 2)) = 160;
	smallImg.at<uchar>(cv::Point(2, 1)) = 160;
	smallImg.at<uchar>(cv::Point(2, 2)) = 220;

	std::cout << "Non-zero elements in array after assigning values: " <<
		cv::countNonZero(smallImg) << std::endl;

	std::cout << "Fisherman img in binary has " << cv::countNonZero(img) <<
		" non-zero pixels" << std::endl;

	cv::imshow("In", img);
	cv::imshow("Small image", smallImg);

	cv::waitKey(0);
}