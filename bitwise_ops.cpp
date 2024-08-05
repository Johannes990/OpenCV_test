#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_bitwise_ops() {
	cv::Mat m1 = (cv::Mat_<uchar>(2, 2) << 1, 1, 0, 0);
	cv::Mat m2 = (cv::Mat_<uchar>(2, 2) << 0, 0, 1, 1);
	cv::Mat m3 = (cv::Mat_<uchar>(2, 2) << 1, 0, 0, 0);
	cv::Mat m4 = (cv::Mat_<uchar>(2, 2) << 0, 1, 0, 1);
	cv::Mat bitwiseAND, bitwiseOR, bitwiseXOR, bitwiseNOT;

	cv::bitwise_not(m3, bitwiseNOT);
	cv::bitwise_and(m1, m4, bitwiseAND);
	cv::bitwise_or(m3, m2, bitwiseOR);
	cv::bitwise_xor(m1, m4, bitwiseXOR);

	std::cout << "M1:\n" << m1 << std::endl;
	std::cout << "M2:\n" << m2 << std::endl;
	std::cout << "M3:\n" << m3 << std::endl;
	std::cout << "M4:\n" << m4 << std::endl;

	std::cout << "Bitwise NOT for M3:\n" << bitwiseNOT << std::endl;
	std::cout << "Bitwise AND for M1 & M4:\n" << bitwiseAND << std::endl;
	std::cout << "Bitwise OR for M3 & M2:\n" << bitwiseOR << std::endl;
	std::cout << "Bitwise XOR for M1 & M4:\n" << bitwiseXOR << std::endl;
}