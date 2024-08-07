#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_sort() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat imgSortedByRows = cv::Mat::zeros(img.size(), img.type());
	cv::Mat imgSortedByCols = cv::Mat::zeros(img.size(), img.type());

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Rows sorted", cv::WINDOW_NORMAL);
	cv::namedWindow("Cols sorted", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Rows sorted", imgSortedByRows);
	cv::imshow("Cols sorted", imgSortedByCols);

	cv::waitKey(0);
}