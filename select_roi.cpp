#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_select_roi() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	cv::selectROI("Img", img, true, true);

	cv::imshow("Img", img);

	cv::waitKey(0);
}