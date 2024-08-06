#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_randn() {
	cv::Mat arraySingleChannel = cv::Mat::zeros(50, 50, CV_8U);
	cv::Mat arrayTripleChannel = cv::Mat::zeros(50, 50, CV_8UC3);
	const double singleMean = 91.564;
	const double singleStdDev = 4.9;
	const cv::Scalar rangeMean = cv::Scalar(50, 200, 50);
	const cv::Scalar rangeStdDev = cv::Scalar(1.0, 40.0, 20.0);

	cv::namedWindow("arraySingle", cv::WINDOW_NORMAL);
	cv::namedWindow("arrayTriple", cv::WINDOW_NORMAL);

	cv::randn(arraySingleChannel, singleMean, singleStdDev);
	cv::randn(arrayTripleChannel, rangeMean, rangeStdDev);

	cv::imshow("arraySingle", arraySingleChannel);
	cv::imshow("arrayTriple", arrayTripleChannel);

	cv::waitKey(0);
}