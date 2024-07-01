#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_distance_transform() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat distanceTransformImg, labels;
	cv::Mat maskDistanceTransform = cv::Mat::ones(cv::Size(5, 5), CV_8UC1);

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("distance transform image output", cv::WINDOW_GUI_NORMAL);

	// input image should (must?) be 8-bit single channel
	cv::threshold(inputImg, inputImg, 90, 255, cv::THRESH_BINARY);

	//cv::distanceTransform(inputImg, distanceTransformImg, cv::DIST_L1, cv::DIST_MASK_PRECISE, CV_8UC1);

	// overloaded - here the labels matrix holds the enumeration values of all zeroes from which distance is calculated
	// so for instance 3 in this case (1, 2, 3)
	maskDistanceTransform.at<uchar>(cv::Point(0, 0)) = 0;
	maskDistanceTransform.at<uchar>(cv::Point(0, 4)) = 0;
	maskDistanceTransform.at<uchar>(cv::Point(4, 1)) = 0;

	cv::distanceTransform(maskDistanceTransform, distanceTransformImg, labels, cv::DIST_L1, cv::DIST_MASK_5, CV_8UC1);

	//cv::imshow("Original image", inputImg);
	//cv::imshow("distance transform image output", distanceTransformImg);
	std::cout << distanceTransformImg << std::endl;
	std::cout << labels << std::endl;

	cv::waitKey(0);
}