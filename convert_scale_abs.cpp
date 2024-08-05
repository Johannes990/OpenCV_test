#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_convert_scale_abs() {
	cv::Mat_<float> A(5, 5);
	cv::randu(A, cv::Scalar(-100), cv::Scalar(100));
	cv::Mat_<float> B = A * 4 + 7;
	cv::Mat out;

	std::cout << "A: " << A << std::endl;
	std::cout << "B: " << B << std::endl;

	cv::convertScaleAbs(B, out);

	std::cout << "B output with converScaleAbs: " << out << std::endl;
}