#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_psnr() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_COLOR);
	cv::Mat img2Color = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\top.jpg", cv::IMREAD_COLOR);
	cv::Mat img3 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\moll.png", cv::IMREAD_COLOR);
	cv::Mat img1NOT, img3Rotated, img2Blur;
	cv::Mat small1 = (cv::Mat_<uchar>(2, 2) << 0, 5, 28, 0);
	cv::Mat small2 = (cv::Mat_<uchar>(2, 2) << 10, 3, 1, 0);
	const double R = 255;

	/*
	* PSNR formula:
	* PSNR = 10 * log_10 (R^2 / MSE)
	* MSE - mean squared error between the arrays
	* 
	*/

	std::cout << "The peak signal to noise ratio between arrays:" << std::endl;
	std::cout << small1 << std::endl;
	std::cout << "and" << std::endl;
	std::cout << small2 << std::endl;
	std::cout << "is: " << cv::PSNR(small1, small2, R) << " dB." << std::endl;

	cv::namedWindow("Im1", cv::WINDOW_NORMAL);
	cv::namedWindow("Im1 not", cv::WINDOW_NORMAL);
	cv::namedWindow("Im2", cv::WINDOW_NORMAL);
	cv::namedWindow("Im2 blur", cv::WINDOW_NORMAL);
	cv::namedWindow("Im3", cv::WINDOW_NORMAL);
	cv::namedWindow("Im3 rotated", cv::WINDOW_NORMAL);

	cv::bitwise_not(img1, img1NOT);
	cv::rotate(img3, img3Rotated, cv::ROTATE_180);
	cv::medianBlur(img2Color, img2Blur, 5);
	
	std::cout << "The PSNR between img1 and img1NOT is: " << cv::PSNR(img1, img1NOT, R) << " dB." << std::endl;
	std::cout << "The PSNR between img2Color and img2Blur is: " << cv::PSNR(img2Color, img2Blur, R) << " dB." << std::endl;
	std::cout << "The PSNR between img3 and img3Rotated is: " << cv::PSNR(img3, img3Rotated, R) << " dB." << std::endl;

	cv::imshow("Im1", img1);
	cv::imshow("Im1 not", img1NOT);
	cv::imshow("Im2", img2Color);
	cv::imshow("Im2 blur", img2Blur);
	cv::imshow("Im3", img3);
	cv::imshow("Im3 rotated", img3Rotated);

	cv::waitKey(0);
}