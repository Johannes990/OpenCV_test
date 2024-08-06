#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_repeat() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\tile.png", cv::IMREAD_COLOR);
	cv::Mat out;
	const int nX = 200;
	const int nY = 150;

	cv::namedWindow("In", cv::WINDOW_KEEPRATIO);
	cv::namedWindow("Out", cv::WINDOW_KEEPRATIO);

	cv::repeat(img, nX, nY, out);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}