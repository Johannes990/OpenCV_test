#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_backgroundsubtractorknn() {
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\VID_20240709_224705.mp4");
	cv::Mat frame;
	// create knn subtractor with default params
	cv::Ptr<cv::BackgroundSubtractorKNN> knn = cv::createBackgroundSubtractorKNN(500, 400, true);

	cv::namedWindow("Input", cv::WINDOW_NORMAL);
	cv::namedWindow("Output", cv::WINDOW_NORMAL);

	while (true) {
		cv::Mat outputFrame;
		video >> frame;

		int ch = cv::waitKey(1);
		if (frame.empty() || (char)ch == 'q') {
			break;
		}

		knn->apply(frame, outputFrame);

		cv::imshow("Input", frame);
		cv::imshow("Output", outputFrame);
	}

	video.release();
	cv::destroyAllWindows();
}