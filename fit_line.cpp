#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_fit_line() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Vec4f line;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, cv::Scalar(0, 200, 220), 1);
	
	for (int i = 0; i < contours.size(); i++) {
		int lineLength = 250;
		cv::fitLine(contours[i], line, cv::DIST_L1, 0, 0.01, 0.01);

		cv::Point p1(line[0] * lineLength + line[2], line[1] * lineLength + line[3]);
		cv::Point p2(-line[0] * lineLength + line[2], -line[1] * lineLength + line[3]);

		cv::line(out, p1, p2, cv::Scalar(90, 120, i * 23), 1);
	}
	

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);

}