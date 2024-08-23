#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_createBackgroundSubtractorMOG2() {
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\VID_20240709_224705.mp4");
	cv::Mat frame;
	cv::Ptr<cv::BackgroundSubtractorMOG2> mog = cv::createBackgroundSubtractorMOG2(20, 50.0, false);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	while (true) {
		video >> frame;

		int ch = cv::waitKey(1);
		if ((char)ch == 'q' || frame.empty()) {
			break;
		}

		cv::Mat outputFrame;
		mog->apply(frame, outputFrame);

		cv::imshow("In", frame);
		cv::imshow("Out", outputFrame);
	}
}