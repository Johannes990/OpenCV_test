#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_perspective_transform() {
	std::vector<cv::Point3f> inputMatrix;
	inputMatrix.push_back(cv::Point3f(25, 35, 45));
	inputMatrix.push_back(cv::Point3f(35, 34, 45));
	inputMatrix.push_back(cv::Point3f(45, 33, 45));
	inputMatrix.push_back(cv::Point3f(55, 32, 45));
	inputMatrix.push_back(cv::Point3f(65, 31, 45));
	inputMatrix.push_back(cv::Point3f(75, 30, 45));
	inputMatrix.push_back(cv::Point3f(85, 29, 45));
	inputMatrix.push_back(cv::Point3f(95, 28, 45));
	inputMatrix.push_back(cv::Point3f(105, 27, 45));
	std::vector<cv::Point3f> outputMatrix;
	cv::Mat transformMatrix = (cv::Mat_<float>(4, 4) << 1.0, 1.0, 1.0, 1.0,
														  1.5, 0.5, 1.5, 1.0,
														  0.5, 1.0, 1.0, 0.5,
														  1.0, 1.0, 3.5, 2.5);

	std::cout << "Input matrix is:\n" << std::endl;
	std::cout << inputMatrix << std::endl;
	std::cout << "\nTransformation matrix is:\n" << std::endl;
	std::cout << transformMatrix << std::endl;

	cv::perspectiveTransform(inputMatrix, outputMatrix, transformMatrix);

	std::cout << "\nThe output matrix is:\n" << std::endl;
	std::cout << outputMatrix << std::endl;
}