#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_backgroundsubtractorknn() {
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\VID_20240709_224705.mp4");
	cv::Mat frame;

	while (true) {
		video >> frame;

		if (frame.empty()) {
			break;
		}

		cv::imshow("Video", frame);

		int ch = cv::waitKey(16);

		if ((char)ch == 'q') {
			break;
		}
	}

	video.release();
	cv::destroyAllWindows();
}