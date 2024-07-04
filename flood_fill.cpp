#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_flood_fill() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat dst = img.clone();
	cv::Mat mask = cv::Mat::zeros(cv::Size(img.cols + 2, img.rows + 2), CV_8UC1);
	cv::Point seedPoint = cv::Point(img.cols / 2, img.rows / 2);
	cv::Rect r;

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Floodfill image", cv::WINDOW_GUI_NORMAL);

	// default, only floods adjacent pixels with the exact same value of the given pixel
	// cv::floodFill(dst, seedPoint, cv::Scalar(255));

	// overloaded, takes loDiff and upDiff to give some leeway
	// if x is value of given pixel at seedPoint coordinates, then flooded pixels are pixels
	// with values in the range [x - loDiff, x  upDiff]
	cv::floodFill(dst, mask, seedPoint, cv::Scalar(255), &r, cv::Scalar(10), cv::Scalar(10), cv::FLOODFILL_MASK_ONLY);
	cv::rectangle(dst, r, cv::Scalar(0), 2);

	cv::imshow("Original image", img);
	cv::imshow("Floodfill image", dst);
	cv::imshow("mask", mask);

	cv::waitKey(0);
}