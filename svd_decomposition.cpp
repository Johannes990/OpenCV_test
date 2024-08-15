#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_svd_decomposition() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatImg, U, W, Vt;

	// SVDecomp takes float input
	img.convertTo(floatImg, CV_32F);
	cv::SVDecomp(floatImg, W, U, Vt);

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}