#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_invert() {
	cv::Mat matrix = (cv::Mat_<float>(2, 2) << 2, 3,
											   3, 0);
	cv::Mat inv;

	cv::invert(matrix, inv);

	std::cout << "Matrix:\n" << matrix << std::endl;
	std::cout << "Inverted matrix:\n" << inv << std::endl;
}