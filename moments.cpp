#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_moments() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, cv::Scalar(90, 40, 255), 2);

	std::vector<cv::Moments> M(contours.size());	// this vector holds our moments

	for (int i = 0; i < contours.size(); i++) {
		M[i] = cv::moments(contours[i]);
		std::cout << M[i].m10 << std::endl;
		
		cv::Point massCenterPoint(M[i].m10 / M[i].m00, M[i].m01 / M[i].m00);
		
		// draw a circle at the mass-center of each contour
		cv::circle(out, massCenterPoint, 2, cv::Scalar(0, 255, 255), cv::FILLED);
	}

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}