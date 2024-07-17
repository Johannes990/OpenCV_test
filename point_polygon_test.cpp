#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_point_polygon_test() {
	cv::Mat img = cv::Mat::zeros(cv::Size(600, 600), CV_8UC1);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::rectangle(img, cv::Point(100, 100), cv::Point(300, 300), cv::Scalar(200, 200, 30), 2);
	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	cv::Point p1 = cv::Point(90, 110);
	cv::Point p2 = cv::Point(101, 110);
	cv::Point p3 = cv::Point(110, 110);

	double outsideContour = cv::pointPolygonTest(contours[0], p1, true);
	double onContour = cv::pointPolygonTest(contours[0], p2, true);
	double insideContour = cv::pointPolygonTest(contours[0], p3, true);

	std::cout << "Return values are now distances to the nearest contour edge" << std::endl;
	std::cout << "Return value for point (" << p1.x << ", " << p1.y << "): " << outsideContour << std::endl;
	std::cout << "Return value for point (" << p2.x << ", " << p2.y << "): " << onContour << std::endl;
	std::cout << "Return value for point (" << p3.x << ", " << p3.y << "): " << insideContour << std::endl;

	cv::namedWindow("picture", cv::WINDOW_GUI_NORMAL);

	cv::imshow("picture", img);

	cv::waitKey(0);
}