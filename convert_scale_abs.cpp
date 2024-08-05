#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_convert_scale_abs() {
	cv::Mat_<uchar> A(5, 5);
	cv::randu(A, cv::Scalar(-100), cv::Scalar(100));
	cv::Mat_<uchar> B = A * 4 + 7;
	cv::Mat out;

	cv::namedWindow("A", cv::WINDOW_NORMAL);
	cv::namedWindow("B", cv::WINDOW_NORMAL);
	cv::namedWindow("B out", cv::WINDOW_NORMAL);

	std::cout << "A:\n" << A << std::endl;
	std::cout << "B:\n" << B << std::endl;

	cv::convertScaleAbs(B, out);

	std::cout << "B output with converScaleAbs:\n" << out << std::endl;

	cv::imshow("A", A);
	cv::imshow("B", B);
	cv::imshow("B out", out);

	cv::waitKey(0);
}