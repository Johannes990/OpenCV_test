#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_min_max() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	cv::imshow("Img", img);

	cv::waitKey(0);
}