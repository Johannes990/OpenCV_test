#include <opencv2\opencv.hpp>


void run_image_contour_drawing() {
	int win_width = 1500;
	int win_height = 1500;
	cv::Mat frame = cv::Mat::zeros(cv::Size(win_height, win_height), CV_8UC3);
	cv::namedWindow("Frame", 0);

	std::vector<std::vector<cv::Point>> contours = {
		{cv::Point(100, 100), cv::Point(100, 130), cv::Point(139, 210), cv::Point(100, 111)},
		{cv::Point(100, 150), cv::Point(200, 430), cv::Point(239, 410), cv::Point(400, 411)},
		{cv::Point(200, 200), cv::Point(300, 330), cv::Point(223, 620), cv::Point(304, 513)},
	};

	for (int i = 0; i < contours.size(); i++) {
		cv::drawContours(frame, contours, i, cv::Scalar(255 - i * 30, 255, 150 + i * 25), 2, cv::LINE_AA);
	}

	cv::imshow("Frame", frame);
	cv::waitKey(0);
}