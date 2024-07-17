#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_hu_moments() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Scalar contourColor = cv::Scalar(40, 50, 255);
	cv::Scalar massCenterColor = cv::Scalar(160, 0, 230);
	int massCenterRadius = 3;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, contourColor, 2);

	std::vector<cv::Moments> M(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		M[i] = cv::moments(contours[i]);
		cv::Point massCenter(M[i].m10 / M[i].m00, M[i].m01 / M[i].m00);

		cv::circle(out, massCenter, massCenterRadius, massCenterColor, cv::FILLED);
	}

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}