#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_create_trackbar() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);
	cv::Mat textOverlay;
	const std::string trackbarName = "Control 1";
	int trackbarValue = 0;
	int trackbarMaxValue = 100;

	cv::namedWindow("Window", cv::WINDOW_FREERATIO);

	cv::createTrackbar(trackbarName, "Window", &trackbarValue, trackbarMaxValue);

	while (true) {
		// this textOverlay Mat is needed so that the text won't be drawn on the original image
		// img.clone() clones the image onto the textOverlay and that is then displayed
		// fresh and new every time we press a key for a new while-loop iteration
		textOverlay = img.clone();

		cv::Point textAnchor = cv::Point(70 + trackbarValue, 70);
		cv::Scalar textColor = cv::Scalar(0 + trackbarValue * 2, 255 - trackbarValue * 2, 255);
		cv::putText(textOverlay, std::to_string(trackbarValue), textAnchor, 2, 2, textColor, 2);

		cv::imshow("Window", textOverlay);

		cv::waitKey(0);
	}
}