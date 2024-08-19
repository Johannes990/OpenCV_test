#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imreadmulti() {
	std::vector<cv::Mat> images;
	const std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pilt.JPG";

	bool isValid = cv::imreadmulti(filename, images);

	std::cout << "read " << images.size() << " images" << std::endl;
	std::cout << "Validity: " << isValid << std::endl;
}