#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dense_optical_flow_calc() {
	cv::Ptr<cv::DISOpticalFlow> disOpticalFlow = cv::DISOpticalFlow::create(cv::DISOpticalFlow::PRESET_ULTRAFAST);
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\VID_20240709_224705.mp4");
	cv::Mat frame, prevFrame, flow;
	const cv::Scalar lineColor = cv::Scalar(0, 255, 0);
	const cv::Scalar circleColor = cv::Scalar(0, 0, 255);

	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	while (true) {
		video >> frame;

		cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

		int ch = cv::waitKeyEx(1);
		if ((char)ch == 'q' || frame.empty()) {
			break;
		}

		if (!prevFrame.empty()) {
			disOpticalFlow->calc(prevFrame, frame, flow);
			
			for (int y = 0; y < frame.rows; y += 25) {
				for (int x = 0; x < frame.cols; x =+ 25) {
					cv::Point2f flowAtPoint = flow.at<cv::Point2f>(y, x);
					cv::line(frame, cv::Point(x, y), cv::Point(cvRound(x + flowAtPoint.x), cvRound(y + flowAtPoint.y)), lineColor, 2);
					cv::circle(frame, cv::Point(x, y), 2, circleColor, cv::FILLED);
				}
			}
		}

		cv::imshow("Out", frame);

		prevFrame = frame.clone();
	}
}