#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_blur_filters() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat gaussianBlurImg, bilateralFilterImg, medianBlurImg;
	cv::Mat median2bilat, canny, gray, flat1, flat2, diff;

	cv::namedWindow("Gaussian Blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Bilateral Blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Median Blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Compound", cv::WINDOW_NORMAL);

	cv::GaussianBlur(img, gaussianBlurImg, cv::Size(5, 5), 100.0);
	cv::bilateralFilter(img, bilateralFilterImg, 7, 250.0, 300);
	cv::medianBlur(img, medianBlurImg, 9);
	cv::bilateralFilter(medianBlurImg, median2bilat, 7, 250, 250);

	cv::cvtColor(median2bilat, gray, cv::COLOR_BGR2GRAY);
	cv::threshold(gray, flat1, 90, 255, cv::THRESH_BINARY);
	cv::threshold(gray, flat2, 140, 255, cv::THRESH_BINARY);
	diff = flat1 - flat2;

	cv::Canny(diff, canny, 1.0, 1.0);

	cv::imshow("Gaussian Blur", gaussianBlurImg);
	cv::imshow("Bilateral Blur", bilateralFilterImg);
	cv::imshow("Median Blur", medianBlurImg);
	cv::imshow("Compound", canny);

	cv::waitKey(0);
}