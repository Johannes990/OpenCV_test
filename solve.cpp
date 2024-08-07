#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_solve() {
	cv::Mat coeffs = (cv::Mat_<float>(3, 3) << 2, 1, -8, 0, 4, 2, 0.25, -0.1, -3);
	cv::Mat freeParams = (cv::Mat_<float>(3, 1) << 2.333333333, 16.666666666, -1.275);
	cv::Mat solution;

	cv::solve(coeffs, freeParams, solution, cv::DECOMP_LU + cv::DECOMP_NORMAL);

	std::cout << "Solution to our equation system with matrix:\n" << std::endl;
	std::cout << coeffs << '\n' << std::endl;
	std::cout << "and free parameters:\n" << std::endl;
	std::cout << freeParams << '\n' << std::endl;
	std::cout << "is:\n" << std::endl;
	std::cout << solution << '\n' << std::endl; // will be [0.5, 4, 0.(3)]

	cv::Mat cubicCoeffs1 = (cv::Mat_<float>(4, 1) << 4, 3, 1.6, -0.771008);
	cv::Mat cubicCoeffs2 = (cv::Mat_<float>(4, 1) << -0.6, 2.8, 1, -14);
	cv::Mat cubicRoots1;
	cv::Mat cubicRoots2;

	cv::solveCubic(cubicCoeffs1, cubicRoots1);
	cv::solveCubic(cubicCoeffs2, cubicRoots2);

	std::cout << "Solution to the cubic equation: c1x^3 + c2x^2 + c3x + c4 = 0" << std::endl;
	std::cout << "with coefficients:\n" << std::endl;
	std::cout << cubicCoeffs1 << '\n' << std::endl;
	std::cout << "is:\n" << std::endl;
	std::cout << cubicRoots1 << '\n' << std::endl; // will be 0.28

	std::cout << "Solution to the cubic equation: c1x^3 + c2x^2 + c3x + c4 = 0" << std::endl;
	std::cout << "with coefficients:\n" << std::endl;
	std::cout << cubicCoeffs2 << '\n' << std::endl;
	std::cout << "is:\n" << std::endl;
	std::cout << cubicRoots2 << '\n' << std::endl; // will be -2
}