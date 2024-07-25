#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_select_roi() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);

	cv::namedWindow("Img", cv::WINDOW_NORMAL);

	// select single region of interest
	cv::Rect r = cv::selectROI(img, true, true);
	std::cout << r.x << " " << r.y << " " << r.width << " " << r.height << std::endl;

	cv::imshow("Img", img);

	cv::waitKey(0);

	// select multiple regions of interest
	std::vector<cv::Rect> roiVec;
	cv::selectROIs("Img", img, roiVec, true, false);

	std::cout << "User selected the following rectangles:" << std::endl;

	for (cv::Rect r : roiVec) {
		std::cout << "x: " << r.x << ", y: " << r.y << ", width: " << r.width << ", height: "
			<< r.height << std::endl;
	}

	cv::waitKey(0);
}