#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_determinant() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken2.jpg", cv::IMREAD_COLOR);
	cv::Mat squareMat;
	double determinant;

	cv::resize(img, squareMat, cv::Size(img.cols, img.cols));
	determinant = cv::determinant(squareMat);

	std::cout << "Determinant: " << determinant << std::endl;

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	cv::imshow("Img", squareMat);

	cv::waitKey(0);
}