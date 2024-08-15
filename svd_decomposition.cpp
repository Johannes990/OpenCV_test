#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_svd_decomposition() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatImg, U, W, Vt;

	// SVDecomp takes float input
	img.convertTo(floatImg, CV_32F);
	cv::SVDecomp(floatImg, W, U, Vt);

	std::cout << "W size: " << W.size() << std::endl;
	std::cout << "U size: " << U.size() << std::endl;
	std::cout << "Vt size: " << Vt.size() << std::endl;

	// W is a stored as a single row but mathematically should be a diagonal matrix
	// let's convert
	cv::Mat diagW = cv::Mat::diag(W);

	cv::Mat res = U * diagW * Vt; // input = U * W * Vt by definition
	cv::convertScaleAbs(res, res); // convert back to unsigned char

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	cv::imshow("In", res);

	cv::waitKey(0);
}