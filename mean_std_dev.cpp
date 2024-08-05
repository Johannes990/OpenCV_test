#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mean_std_dev() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken2.jpg", cv::IMREAD_COLOR);
	cv::Mat mean, stdDev;

	cv::meanStdDev(img, mean, stdDev);

	std::cout << "Mean: " << mean << std::endl;
	std::cout << "Standard deviation: " << stdDev << std::endl;
}