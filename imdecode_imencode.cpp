#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imdecode_imencode() {
	cv::Mat image = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\4colors.png", cv::IMREAD_COLOR);

	cv::namedWindow("img -> membuffer -> img", cv::WINDOW_NORMAL);

	cv::imshow("img -> membuffer -> img", image);

	cv::waitKey(0);
}