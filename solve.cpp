#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_solve() {
	cv::Mat coeffs = (cv::Mat_<float>(3, 3) << 2, 1, -8, 0, 4, 2, 0.25, -0.1, -3);
	cv::Mat freeParams = (cv::Mat_<float>(3, 1) << 2.333333333, 16.666666666, -1.275);
	cv::Mat solution;

	cv::solve(coeffs, freeParams, solution, cv::DECOMP_LU);

	std::cout << "Solution to our equation system:" << std::endl;
	std::cout << solution << std::endl;
}