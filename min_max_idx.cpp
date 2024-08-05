#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_min_max_idx() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken2.jpg", cv::IMREAD_GRAYSCALE);
	double minVal;
	double maxVal;
	int minIdx[2]; // array to keep the min value x and y axis indices
	int maxIdx[2]; // array to keep the max value x and y axis indices

	cv::minMaxIdx(img, &minVal, &maxVal, minIdx, maxIdx);

	std::cout << "Minimum value: " << minVal << std::endl;
	std::cout << "Maximum value: " << maxVal << std::endl;
	std::cout << "Minimum idx x: " << minIdx[0] << ", y: " << minIdx[1] << std::endl; // 45, 1769
	std::cout << "Maximum idx x: " << maxIdx[0] << ", y: " << maxIdx[1] <<std::endl; // 1113, 1664

	// let's check
}