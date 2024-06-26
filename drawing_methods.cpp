#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_drawing_functions() {
	cv::Mat maskImg = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);

	cv::namedWindow("Mask", cv::WINDOW_KEEPRATIO);

	int x = 100;
	int y = 150;
	int clipLineX = 450;
	int clipLineY = 450;
	int radius = 100;
	int thickness = 1;
	int ratio = 1;
	
	cv::Point p1 = cv::Point(500, 500);
	cv::Point p2 = cv::Point(clipLineX, clipLineY);

	cv::createTrackbar("Point 1", "Mask", &x, 800);
	cv::createTrackbar("Point 2", "Mask", &y, 800);
	cv::createTrackbar("Radius", "Mask", &radius, 500);
	cv::createTrackbar("Thickness", "Mask", &thickness, 10);
	cv::createTrackbar("Ratio", "Mask", &ratio, 5);
	cv::createTrackbar("Clip Line X", "Mask", &clipLineX, 800);
	cv::createTrackbar("Clip Line Y", "Mask", &clipLineY, 800);

	while (true) {
		// over-writing
		maskImg = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
		p2 = cv::Point(clipLineX, clipLineY);

		// rectangle
		cv::rectangle(maskImg, cv::Point(0, 0), cv::Point(x, y), cv::Scalar(255, 0, 0), thickness, cv::LINE_4);

		// circle
		cv::circle(maskImg, cv::Point(400, 400), radius, cv::Scalar(120, 240, 160), thickness, cv::LINE_AA);

		// regular line
		cv::line(maskImg, cv::Point(600, 500), cv::Point(600, 800), cv::Scalar(200, 100, 0), thickness, cv::LINE_AA);

		// line with an arrow pointing towards the end
		cv::arrowedLine(maskImg, cv::Point(500, 500), cv::Point(750, 500), cv::Scalar(120, 240, 160), thickness, cv::LINE_AA, 0, (double)ratio / 10.0);

		// clipline - returns true when inside some bounding rectangle defined by two points(?)
		// this does not actually draw the line, therefore we draw it again after to visualize
		std::cout << cv::clipLine(cv::Size(x, y), p1, p2) << std::endl;
		cv::line(maskImg, p1, p2, cv::Scalar(255, 255, 255), thickness, cv::LINE_4);

		cv::imshow("Mask", maskImg);

		int ch = cv::waitKey(1);
		if ((char)ch == 'Q') {
			break;
		}
	}
}