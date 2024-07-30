#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_multiply() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat mask = cv::Mat::ones(img.size(), img.type());
	cv::Mat out;
	const float scale = 0.02;
	int notches = 50;

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::createTrackbar("Scale", "Out", &notches, 100);

	// open-mask multiplication
	cv::multiply(img, mask, out, 1.0);

	cv::imshow("In", img);
	cv::imshow("Out", out); // image turned blue???
							// by default, only multiplies the first channel, which is blue

	cv::waitKey(0);

	// change mask to cut out an eight of the picture
	// from the lower right part
	for (int i = mask.cols / 2; i < mask.cols; i++) {
		for (int j = mask.rows * 0.75; j < mask.rows; j++) {
			mask.at<cv::Vec3b>(cv::Point(i, j)) = 0;
		}
	}

	while (true) {
		cv::multiply(img, mask, out, scale * notches);

		cv::imshow("Out", out);

		int c = cv::waitKey(5);

		if ((char)c == 'q') {
			break;
		}
	}
}