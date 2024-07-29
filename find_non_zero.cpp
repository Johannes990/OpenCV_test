#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_find_non_zero() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat input = cv::Mat::zeros(3, 3, CV_8UC1);
	cv::Mat nonZero;
	cv::Mat locations;
	cv::Mat locationsForImg;
	input.at<uchar>(cv::Point(0, 0)) = 200;
	input.at<uchar>(cv::Point(1, 1)) = 200;
	input.at<uchar>(cv::Point(0, 2)) = 200;

	cv::threshold(input, nonZero, 100, 255, cv::THRESH_BINARY);
	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);
	cv::findNonZero(nonZero, locations);
	cv::findNonZero(img, locationsForImg);

	cv::namedWindow("Nonzero", cv::WINDOW_NORMAL);

	std::cout << "found " << locations.size() << 
		" non-zero locations in the small array" << std::endl;
	std::cout << "coordinates found:" << std::endl;
	std::cout << locations << std::endl;

	std::cout << "found " << locationsForImg.size() <<
		" non-zero locations in the large array" << std::endl;

	cv::imshow("Nonzero", nonZero);

	cv::waitKey(0);
}