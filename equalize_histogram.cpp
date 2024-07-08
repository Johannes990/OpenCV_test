#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_equalize_histogram() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat histogram;

	cv::namedWindow("Input image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Histogram equalization", cv::WINDOW_GUI_NORMAL);

	// this function takes a single-channel image
	// for color images, we need to split input image into 3 channels
	std::vector<cv::Mat> channels;

	cv::split(inputImg, channels); // split
	cv::equalizeHist(channels[0], channels[0]); // do equalize histogram
	cv::equalizeHist(channels[1], channels[1]);
	cv::equalizeHist(channels[2], channels[2]);
	cv::merge(channels, histogram); // merge channels into a single image

	cv::imshow("Input image", inputImg);
	cv::imshow("Histogram equalization", histogram);
	
	cv::waitKey(0);
}