#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_insert_channel() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat output = img.clone();
	cv::Mat redChannel;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	// OpenCV uses BGR so red is channel 2
	cv::extractChannel(img, redChannel, 2);

	// swap the blue channel with our green channel
	cv::insertChannel(redChannel, output, 1);

	cv::imshow("In", img);
	cv::imshow("Out", output);

	cv::waitKey(0);
}