#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_compare() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat one = cv::Mat::zeros(cv::Size(3, 3), CV_8UC1);
	cv::Mat two = cv::Mat::zeros(cv::Size(3, 3), CV_8UC1);
	cv::Mat compareOut;

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	one.at<uchar>(cv::Point(0, 0)) = 5;
	one.at<uchar>(cv::Point(1, 1)) = 15;
	one.at<uchar>(cv::Point(2, 2)) = 25;

	two.at<uchar>(cv::Point(0, 0)) = 5;
	two.at<uchar>(cv::Point(1, 1)) = 15;
	two.at<uchar>(cv::Point(2, 2)) = 25;

	cv::compare(one, two, compareOut, cv::CMP_EQ);

	// all white when elements equal (comparison operator true)
	cv::imshow("In", compareOut);

	cv::waitKey(0);

	// change an element of the second array
	two.at<uchar>(cv::Point(0, 0)) = 125;

	cv::compare(one, two, compareOut, cv::CMP_EQ);

	cv::imshow("In", compareOut);

	cv::waitKey(0);
}