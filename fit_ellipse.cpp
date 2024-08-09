#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_fit_ellipse() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_COLOR);
	cv::Mat out = cv::Mat::zeros(img.size(), img.type());
	cv::Mat grayImg;
	cv::Scalar contourColor = cv::Scalar(0, 150, 250);
	cv::Scalar ellipseColor = cv::Scalar(200, 0, 170);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	cv::threshold(grayImg, grayImg, 100, 255, cv::THRESH_BINARY);
	cv::findContours(grayImg, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, contourColor, 1);

	for (int i = 0; i < contours.size(); i++) {
		if (contours[i].size() >= 5) {
			cv::RotatedRect r = cv::fitEllipse(contours[i]);// fitEllipse approximates the shape only
															// it does not necessarily give ellipses that contain the contour absolutely
			cv::ellipse(out, r, ellipseColor, 1, cv::LINE_AA);

		}
	}

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}