#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_min_max_loc() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken2.jpg", cv::IMREAD_GRAYSCALE);
	cv::Point minLoc;
	cv::Point maxLoc;
	double minVal;
	double maxVal;

	// input must be a single channel array
	cv::minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc);

	std::cout << "Minimum value: " << minVal << std::endl;
	std::cout << "Maximum value: " << maxVal << std::endl;
	std::cout << "Minimum location: " << minLoc << std::endl;
	std::cout << "Maximum location: " << maxLoc << std::endl;
}