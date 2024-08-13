#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_calc_covariation_matrix() {
	cv::Mat input = (cv::Mat_<float>(4, 2) <<
		4.5, 6,
		223, 0,
		-0, 19,
		0, 1.01
		);
	cv::Mat meanOut, covarOut;

	cv::calcCovarMatrix(input, covarOut, meanOut, cv::COVAR_NORMAL | cv::COVAR_ROWS, CV_32F);

	std::cout << input << std::endl;
	std::cout << covarOut << std::endl;
	std::cout << meanOut << std::endl;
}