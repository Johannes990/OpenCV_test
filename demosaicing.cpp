#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_demosaicing() {
	cv::Mat mask = cv::Mat::zeros(cv::Size(6, 6), CV_8UC1);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	mask.at<uchar>(cv::Point(1, 1)) = 100;
	mask.at<uchar>(cv::Point(2, 2)) = 50;
	mask.at<uchar>(cv::Point(3, 3)) = 122;
	mask.at<uchar>(cv::Point(4, 4)) = 0;
	mask.at<uchar>(cv::Point(5, 5)) = 90;
	mask.at<uchar>(cv::Point(0, 0)) = 131;
	mask.at<uchar>(cv::Point(2, 1)) = 41;

	cv::imshow("In", mask);

	// pretty cool way of calculating the green, red and blue values actuall
	cv::demosaicing(mask, mask, cv::COLOR_BayerRG2BGR);

	cv::imshow("Out", mask);

	std::cout << mask.size() << std::endl;

	cv::waitKey(0);
}