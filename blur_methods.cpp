#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_blur_filters() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\IMG_20240624_182926.jpg", cv::IMREAD_COLOR);
	cv::Mat gaussianBlurImg, bilateralFilterImg, medianBlurImg;

	cv::namedWindow("Gaussian Blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Bilateral Blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Median Blur", cv::WINDOW_NORMAL);

	cv::GaussianBlur(img, gaussianBlurImg, cv::Size(5, 5), 100.0);
	cv::bilateralFilter(img, bilateralFilterImg, 5, 1.0, 1.0);
	cv::medianBlur(img, medianBlurImg, 5);

	cv::imshow("Gaussian Blur", gaussianBlurImg);
	cv::imshow("Bilateral Blur", bilateralFilterImg);
	cv::imshow("Median Blur", medianBlurImg);

	cv::waitKey(0);
}