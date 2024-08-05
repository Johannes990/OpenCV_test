#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_eigen() {
	cv::Mat matrix = cv::Mat::zeros(3, 3, CV_32FC1);
	cv::Mat eigenVectors, eigenValues;

	matrix.at<float>(cv::Point(1, 0)) = 5.5;
	matrix.at<float>(cv::Point(2, 0)) = 1.0;
	matrix.at<float>(cv::Point(1, 2)) = 0.5;
	matrix.at<float>(cv::Point(2, 2)) = 1.33333;
	matrix.at<float>(cv::Point(0, 2)) = 0.21717;

	std::cout << matrix << std::endl;

	cv::eigen(matrix, eigenValues, eigenVectors);

	std::cout << "Eigen vectors: " << eigenVectors << std::endl;
	std::cout << "Eigen values: " << eigenValues << std::endl;
}