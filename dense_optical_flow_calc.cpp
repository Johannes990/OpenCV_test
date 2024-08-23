#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dense_optical_flow_calc() {
	cv::Ptr<cv::DISOpticalFlow> disOpticalFlow = cv::DISOpticalFlow::create();
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\VID_20240709_224705.mp4");
	cv::Mat frame, prevFrame, flow;
	const cv::Scalar lineColor(0, 255, 0);
	const cv::Scalar circleColor(0, 0, 255);

	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	while (true) {
		video >> frame;

		cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

		int ch = cv::waitKey(1);
		if ((char)ch == 'q' || frame.empty()) {
			break;
		}

		if (!prevFrame.empty()) {
			disOpticalFlow->calc(prevFrame, frame, flow);

			for (int y = 0; y < frame.rows; y++) {
				for (int x = 0; x < frame.cols; x++) {
					cv::Point2f flowAtPoint = flow.at<cv::Point2f>(y, x);
					cv::line(frame, cv::Point(x, y), cv::Point(cvRound(x + flowAtPoint.x), cvRound(y + flowAtPoint.y)), lineColor, 3);
					cv::circle(frame, cv::Point(x, y), 3, circleColor, cv::FILLED);
				}
			}
		}

		cv::imshow("Out", frame);

		prevFrame = frame.clone();
	}
}