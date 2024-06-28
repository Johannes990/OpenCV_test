#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_polar_transformations() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat linearPolarImg = cv::Mat::zeros(inputImg.size(), inputImg.type());
	cv::Mat logPolarImg = cv::Mat::zeros(inputImg.size(), inputImg.type());
	cv::Mat warpPolarImg = cv::Mat::zeros(inputImg.size(), inputImg.type());
	int flags = cv::INTER_LINEAR + cv::WARP_FILL_OUTLIERS; // not sure if these flags really change anything for us

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Linear polar warped image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Logpolar warped image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Warp polar warped image", cv::WINDOW_GUI_NORMAL);

	int maxRadius = inputImg.size().width / 2;
	cv::Point2f center(maxRadius, maxRadius);

	// linear to polar
	cv::warpPolar(inputImg, warpPolarImg, cv::Size(inputImg.size().width, inputImg.size().height + 300), center, maxRadius, flags + cv::WARP_INVERSE_MAP);

	// polar to linear
	cv::warpPolar(warpPolarImg, linearPolarImg, inputImg.size(), center, maxRadius, flags + cv::WARP_POLAR_LINEAR);

	// polar log
	cv::warpPolar(warpPolarImg, logPolarImg, inputImg.size(), center, maxRadius, flags + cv::WARP_POLAR_LOG);

	cv::imshow("Original image", inputImg);
	cv::imshow("Linear polar warped image", linearPolarImg);
	cv::imshow("Logpolar warped image", logPolarImg);
	cv::imshow("Warp polar warped image", warpPolarImg);

	cv::waitKey(0);
}