#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mean() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg");
	cv::Mat out = cv::Mat::zeros(cv::Size(3, 3), CV_8UC1);
	float pictureMean;

	cv::namedWindow("Image", cv::WINDOW_NORMAL);

	out.at<uchar>(cv::Point(0, 2)) = 5;
	out.at<uchar>(cv::Point(1, 2)) = 45;
	out.at<uchar>(cv::Point(2, 1)) = 55;
	out.at<uchar>(cv::Point(2, 2)) = 15;

	std::cout << cv::mean(out) << std::endl;
	std::cout << "Trashcan image mean value is: " << cv::mean(img) << std::endl;

	cv::imshow("Image", out);

	cv::waitKey(0);
}