#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_determinant() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken2.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat squareMat, square32F, smallMat;
	double determinant;

	cv::resize(img, squareMat, cv::Size(img.cols, img.cols));
	squareMat.convertTo(square32F, CV_32F);
	smallMat = cv::Mat::zeros(cv::Size(4, 4), CV_32F);
	smallMat.at<float>(0, 0) = 0.5f;
	smallMat.at<float>(0, 1) = 0.10f;
	smallMat.at<float>(0, 2) = 0.02f;
	smallMat.at<float>(0, 3) = 3.50f;
	smallMat.at<float>(1, 0) = 0.60f;
	smallMat.at<float>(1, 3) = 0.40f;
	smallMat.at<float>(2, 3) = 0.50f;
	smallMat.at<float>(3, 3) = 0.30f;

	// a 3000 x 3000 pixel picture determinant is calculated for a long time
	//determinant = cv::determinant(square32F);

	std::cout << smallMat << std::endl;

	determinant = cv::determinant(smallMat);

	std::cout << "Determinant: " << determinant << std::endl;

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	cv::imshow("Img", squareMat);

	cv::waitKey(0);
}