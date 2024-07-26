#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_hconcat_vconcat() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg");

	cv::namedWindow("Vertical concat", cv::WINDOW_NORMAL);
	cv::namedWindow("Horizontal concat", cv::WINDOW_NORMAL);

	cv::imshow("Vertical concat", img1);
	cv::imshow("Horizontal concat", img2);

	cv::waitKey(0);
}