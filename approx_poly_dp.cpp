#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_approx_poly_dp() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	cv::Mat out2 = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out2", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, contours, -1, cv::Scalar(104, 154, 85), 1);

	// print out vector space usage just for interest
	size_t size = sizeof(contours[0][0]);
	int totalCapacity = 0;
	for (int i = 0; i < contours.size(); i++) {
		totalCapacity += contours[i].capacity();
	}
	std::cout << "A single cv::Point uses " << size << " bytes of memory." << std::endl;
	std::cout << "There are " << totalCapacity << " points in the contours vector" << std::endl;
	std::cout << "Contours vector is using " << size * totalCapacity << " bytes of memory." << std::endl;

	cv::Point2f center;
	float radius;
	double epsilon = 1.0; // the smaller this number is, the more precise the approximation

	// find and draw approximate curves that are calculated from the contours
	for (int i = 0; i < contours.size(); i++) {
		cv::minEnclosingCircle(contours[i], center, radius);
		std::cout << "Contour points: " << contours[i].size() << std::endl;
		cv::approxPolyDP(contours[i], contours[i], epsilon, true);
		std::cout << "Approximation points: " << contours[i].size() << std::endl;
	}
	cv::drawContours(out2, contours, -1, cv::Scalar(90, 200, 167), 1);

	cv::imshow("In", img);
	cv::imshow("Out", out);
	cv::imshow("Out2", out2);

	cv::waitKey(0);
}