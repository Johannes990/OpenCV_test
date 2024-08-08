#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dft() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatArray, dftArray;

	img.convertTo(floatArray, CV_32F);
	cv::dft(floatArray, dftArray);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", dftArray);

	cv::waitKey(0);
}