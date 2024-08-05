#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_check_range() {
	cv::Mat mat = (cv::Mat_<uchar>(3, 3) << 
		100, 40, 25,
		201, 10, 9,
		10, 75, 224);
	const double minVal = 10.0;
	const double maxVal = 225.0;
	const bool quiet = false;

	// if quiet is true, then no error given when checkRange fails
	// if quiet false, Exception thrown
	try {
		std::cout << cv::checkRange(mat, quiet, nullptr, minVal, maxVal) << std::endl;
	}
	catch (cv::Exception& e) {
		std::cerr << e.what() << std::endl;
	}
}