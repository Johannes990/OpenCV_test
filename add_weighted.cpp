#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_add_weighted() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\moll.png", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg", cv::IMREAD_COLOR);
	cv::Mat out;
	const double alpha = 0.45;
	const double beta = 1 - alpha;
	const double gamma = 0.0;

	cv::resize(img1, img1, cv::Size(img2.cols, img2.rows));

	cv::namedWindow("In1", cv::WINDOW_NORMAL);
	cv::namedWindow("In2", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In1", img1);
	cv::imshow("In2", img2);

	cv::addWeighted(img1, alpha, img2, beta, gamma, out);

	cv::imshow("Out", out);

	cv::waitKey(0);
}