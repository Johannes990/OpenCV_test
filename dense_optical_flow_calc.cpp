#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dense_optical_flow_calc() {
	cv::Ptr<cv::DISOpticalFlow> disOpticalFlow = cv::DISOpticalFlow::create();
	cv::VideoCapture video = cv::VideoCapture("C:\\Users\\johan\\Videos\\56310-479197605_tiny.mp4");
	cv::Mat frame, prevFrame, flow, displayFrame;
	const cv::Scalar lineColor = cv::Scalar(0, 0, 0);
	const cv::Scalar circleColor = cv::Scalar(0, 0, 255);
	int cnt = 0;

	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	while (true) {
		video >> frame;
		if (frame.empty()) {
			break;
		}

		int ch = cv::waitKey(1);
		if ((char)ch == 'q') {
			break;
		}

		displayFrame = frame.clone();

		cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

		if (!prevFrame.empty() && cnt % 3 == 0) {
			disOpticalFlow->calc(prevFrame, frame, flow);
			
			for (int y = 0; y < frame.rows; y += 25) {
				for (int x = 0; x < frame.cols; x += 25) {
					cv::Point2f flowAtPoint = flow.at<cv::Point2f>(y, x);
					cv::line(displayFrame, cv::Point(x, y), cv::Point(int(x + flowAtPoint.x), int(y + flowAtPoint.y)), lineColor, 2);
					cv::circle(displayFrame, cv::Point(x, y), 2, circleColor);
				}
			}
		}
		
		if (cnt % 4 == 0) {
			prevFrame = frame.clone();
		}

		cv::imshow("Out", displayFrame);

		cnt++;
	}
}