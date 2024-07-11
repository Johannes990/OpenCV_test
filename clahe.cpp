#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_clahe() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat dst;
	std::vector<cv::Mat> channels;
	cv::split(img, channels);
	const int contrastClipLimit = 250;

	// do our smart CLAHE stuff
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(contrastClipLimit, cv::Size(5, 5));
	clahe->apply(channels[0], channels[0]);
	clahe->apply(channels[1], channels[1]);
	clahe->apply(channels[2], channels[2]);

	// do the regular equalizeHist stuff
	// cv::equalizeHist(channels[0], channels[0]);
	// cv::equalizeHist(channels[1], channels[1]);
	// cv::equalizeHist(channels[2], channels[2]);

	cv::merge(channels, dst);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", dst);

	cv::waitKey(0);
}