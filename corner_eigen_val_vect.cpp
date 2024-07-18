#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_corner_eigen_val_vect() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat imgGray;

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", imgGray);

	cv::waitKey(0);
}