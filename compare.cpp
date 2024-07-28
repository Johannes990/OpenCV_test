#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_compare() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat one = cv::Mat::zeros(cv::Size(3, 3), CV_8UC1);
	cv::Mat two = cv::Mat::zeros(cv::Size(3, 3), CV_8UC1);
	cv::Mat compareEq, compareGT, compareLT;

	cv::namedWindow("win 1", cv::WINDOW_NORMAL);
	cv::namedWindow("win 2", cv::WINDOW_NORMAL);
	cv::namedWindow("win 3", cv::WINDOW_NORMAL);

	one.at<uchar>(cv::Point(0, 0)) = 5;
	one.at<uchar>(cv::Point(1, 1)) = 15;
	one.at<uchar>(cv::Point(2, 2)) = 25;

	two.at<uchar>(cv::Point(0, 0)) = 5;
	two.at<uchar>(cv::Point(1, 1)) = 15;
	two.at<uchar>(cv::Point(2, 2)) = 25;

	cv::compare(one, two, compareEq, cv::CMP_EQ);

	// all white when elements equal (comparison operator true)
	cv::imshow("win 1", compareEq);

	cv::waitKey(0);

	// change an element of the second array
	two.at<uchar>(cv::Point(0, 0)) = 125;

	cv::compare(one, two, compareEq, cv::CMP_EQ);
	cv::compare(one, two, compareGT, cv::CMP_GT);
	cv::compare(one, two, compareLT, cv::CMP_LT);

	cv::imshow("win 1", compareEq);
	cv::imshow("win 2", compareGT);
	cv::imshow("win 3", compareLT);

	cv::waitKey(0);
}