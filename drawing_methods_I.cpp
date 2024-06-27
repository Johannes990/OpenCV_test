#include <opencv2\opencv.hpp>
#include "opencv_test.h"
#include <vector>


void run_drawing_methods_I() {
	cv::namedWindow("Mask", cv::WINDOW_KEEPRATIO);

	int x = 100;
	int y = 150;
	int radius = 100;
	int thickness = 1;
	int ratio = 1;
	int clipLineX = 450;
	int clipLineY = 450;
	int ellipseWidth = 70;
	int ellipseHeight = 70;
	int angle = 0;
	int startAngle = 0;
	int endAngle = 360;
	int ellipse2PolyDelta = 5;
	cv::Mat maskImg = cv::Mat::zeros(cv::Size(1000, 1200), CV_8UC3);
	cv::Point clipLineEndX = cv::Point(500, 500);
	cv::Point clipLlineEndY = cv::Point(clipLineX, clipLineY);
	cv::Point ellipseCenter = cv::Point(800, 200);
	std::vector<cv::Point> ellipsePoints;

	cv::createTrackbar("X", "Mask", &x, 800);
	cv::createTrackbar("Y", "Mask", &y, 800);
	cv::createTrackbar("Radius", "Mask", &radius, 500);
	cv::createTrackbar("Thickness", "Mask", &thickness, 10);
	cv::createTrackbar("Ratio", "Mask", &ratio, 5);
	cv::createTrackbar("Clip Line X", "Mask", &clipLineX, 800);
	cv::createTrackbar("Clip Line Y", "Mask", &clipLineY, 800);
	cv::createTrackbar("Ellipse width", "Mask", &ellipseWidth, 400);
	cv::createTrackbar("Ellipse height", "Mask", &ellipseHeight, 400);
	cv::createTrackbar("Ellipse angle", "Mask", &angle, 360);
	cv::createTrackbar("Ellipse start angle", "Mask", &startAngle, 360);
	cv::createTrackbar("Ellipse end angle", "Mask", &endAngle, 360);

	while (true) {
		// over-writing
		maskImg = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
		clipLlineEndY = cv::Point(clipLineX, clipLineY);

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
		std::cout << cv::clipLine(cv::Size(x, y), clipLineEndX, clipLlineEndY) << std::endl;
		cv::line(maskImg, clipLineEndX, clipLlineEndY, cv::Scalar(255, 255, 255), thickness, cv::LINE_4);

		// ellipse
		//cv::ellipse(maskImg, ellipseCenter, cv::Size(ellipseWidth, ellipseHeight), angle, startAngle, endAngle, cv::Scalar(0, 100, 200), thickness);

		// ellipse 2 poly function, here we use the same parameters as the previously drawn ellipsepoints are held in vector ellipsePoints
		// then after points are found, we draw them in a different color than the original ellipse
		cv::ellipse2Poly(ellipseCenter, cv::Size(ellipseWidth, ellipseHeight), angle, startAngle, endAngle, ellipse2PolyDelta, ellipsePoints);
		for (int i = 0; i < ellipsePoints.size(); i++) {
			maskImg.at<cv::Vec3b>(ellipsePoints[i])[0] = 200;
			maskImg.at<cv::Vec3b>(ellipsePoints[i])[1] = 10;
			maskImg.at<cv::Vec3b>(ellipsePoints[i])[2] = 10;
		}

		cv::imshow("Mask", maskImg);

		int ch = cv::waitKey(1);
		if ((char)ch == 'Q') {
			break;
		}
	}
}