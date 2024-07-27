#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_insert_channel() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat output = img.clone();
	cv::Mat greenChannel;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	// OpenCV uses BGR so green is channel 1
	cv::extractChannel(img, greenChannel, 1);

	// swap the blue channel with our green channel
	cv::insertChannel(greenChannel, output, 0);

	cv::imshow("In", img);
	cv::imshow("Out", output);

	cv::waitKey(0);
}