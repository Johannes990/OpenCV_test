#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imreadmulti() {
	std::vector<cv::Mat> images;
	std::string windowName = "page number 0";
	const std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\multipage_tif_example.tif";

	// this checks to see if the provided string actually points to an openable image
	// to prevent crashing with wrong input
	if (cv::haveImageReader(filename)) {
		cv::imreadmulti(filename, images);
	}
	
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	for (int i = 0; i < images.size(); i++) {
		cv::imshow(windowName, images[i]);
		cv::waitKey(0);
		cv::destroyWindow(windowName);
		windowName = "page number " + std::to_string(i + 1);
	}
}