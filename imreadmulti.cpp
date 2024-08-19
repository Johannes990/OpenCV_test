#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imreadmulti() {
	std::vector<cv::Mat> images;
	std::string windowName = "page number 0";
	const std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\multipage_tif_example.tif";

	bool isValid = cv::imreadmulti(filename, images);

	std::cout << "read " << images.size() << " images" << std::endl;
	std::cout << "Validity: " << isValid << std::endl;

	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	for (int i = 0; i < images.size(); i++) {
		cv::imshow(windowName, images[i]);
		cv::waitKey(0);
		cv::destroyWindow(windowName);
		windowName = "page number " + std::to_string(i + 1);
	}
}