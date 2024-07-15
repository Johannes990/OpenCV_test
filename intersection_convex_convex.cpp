#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_intersect_convex_convex() {
	cv::Mat base = cv::Mat::zeros(cv::Size(1000, 800), CV_8UC3);
	cv::Scalar polyColor = cv::Scalar(200, 0, 230);
	int polyLineThickness = 2;
	std::vector<cv::Point> poly1 = { {100, 100}, {500, 100}, {500, 500}, {100, 500} };
	std::vector<cv::Point> poly2 = { {300, 300}, {800, 300}, {650, 650} };
	std::vector<cv::Point> intersectionPoly;
	float intersectionPolyArea = 0.0;

	cv::polylines(base, poly1, true, polyColor, polyLineThickness);
	cv::polylines(base, poly2, true, polyColor, polyLineThickness);

	std::cout << "intersection point before intersectConvexConvex count: " << intersectionPoly.size() << std::endl;

	// check if our polygons are actually convex
	if (cv::isContourConvex(poly1) && cv::isContourConvex(poly2)) {
		intersectionPolyArea = cv::intersectConvexConvex(poly1, poly2, intersectionPoly);
	}

	cv::fillPoly(base, intersectionPoly, cv::Scalar(100, 255, 100), cv::LINE_AA);

	std::cout << "intersection point after intersectConvexConvex count: " << intersectionPoly.size() << std::endl;
	std::cout << "Intersection polygon area is: " << intersectionPolyArea << std::endl;

	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Out", base);

	cv::waitKey(0);
}