#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_get_trackbar_pos() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	const std::string trackbar1Name = "Control 1";
	const std::string trackbar2Name = "Control 2";
	const std::string trackbar3Name = "Control 3";
	int trackbarValue = 0;
	int trackbarMaxValue = 100;

	cv::namedWindow("Window", cv::WINDOW_FREERATIO);

	cv::createTrackbar(trackbar1Name, "Window", &trackbarValue, trackbarMaxValue);
	cv::createTrackbar(trackbar2Name, "Window", &trackbarValue, trackbarMaxValue);
	cv::createTrackbar(trackbar3Name, "Window", &trackbarValue, trackbarMaxValue);

	while (true) {
		cv::imshow("Window", img);

		std::cout << "Control 1 current value: " << cv::getTrackbarPos("Control 1", "Window") << std::endl;
		std::cout << "Control 2 current value: " << cv::getTrackbarPos("Control 2", "Window") << std::endl;
		std::cout << "Control 3 current value: " << cv::getTrackbarPos("Control 3", "Window") << std::endl;
		std::cout << std::endl;

		cv::waitKey(0);
	}
}