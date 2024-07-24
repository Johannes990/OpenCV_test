#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_hough_lines() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\lines.jpg", cv::IMREAD_COLOR);
	cv::Mat binary;
	cv::Mat out = img.clone();
	std::vector<cv::Vec4f> lines;
	const double rho = 1;
	const double theta = CV_PI / 180;
	const int threshold = 250;
	const double minLineLength = 250;
	const double maxLineGap = 10.0;

	cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
	cv::threshold(img, binary, 118, 255, cv::THRESH_BINARY);
	// The output vector of lines will hold all found lines as
	// 4-element vectors (x1, y1, x2, y2) where x1, y1 are the coordinates
	// of the first line endpoint and x2, y2 are the coordinates of the
	// second line endpoint
	// rho - the distance resolution of the accumulator
	// theta - the angle resolution of the accumulator
	//
	cv::HoughLinesP(binary, lines, rho, theta, threshold, minLineLength, maxLineGap);

	std::cout << lines.size() << std::endl;

	for (int i = 0; i < lines.size(); i++) {
		cv::Point start = cv::Point(lines[i][0], lines[i][1]);
		cv::Point end = cv::Point(lines[i][2], lines[i][3]);

		cv::line(out, start, end, cv::Scalar(255, 0, 255), 1);
	}

	cv::namedWindow("Img", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Img", binary);
	cv::imshow("Out", out);

	cv::waitKey(0);
}