#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_phase() {
	cv::Mat xCoords = (cv::Mat_<float>(2, 1) << 2.214, 1);
	cv::Mat yCoords = (cv::Mat_<float>(2, 1) << 1, 6);
	cv::Mat angles;
	const bool angleUnitsToDegrees = false;

	// atan2() gives same result as the cv::phase() function, if phase is set
	// to calculate result in radians
	for (int i = 0; i < 2; i++) {
		std::cout << std::atan2(yCoords.at<float>(i, 0), xCoords.at<float>(i, 0)) << std::endl;
	}

	cv::phase(xCoords, yCoords, angles, angleUnitsToDegrees);

	std::cout << angles << std::endl;
}