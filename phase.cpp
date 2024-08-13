#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_phase() {
	cv::Mat xCoords = (cv::Mat_<float>(2, 1) << 2.214, 1);
	cv::Mat yCoords = (cv::Mat_<float>(2, 1) << 1, 6);
	cv::Mat angles;
	const bool angleUnitsToDegrees = true;


	cv::phase(xCoords, yCoords, angles, angleUnitsToDegrees);

	std::cout << angles << std::endl;
}