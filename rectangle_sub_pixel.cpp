#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_rectangle_sub_pixel() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat croppedImg;

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Cropped rectangle image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Cropped with Rect image", cv::WINDOW_GUI_NORMAL);

	// cropping with getRectSubPix()
	cv::getRectSubPix(inputImg, cv::Size(25, 25), cv::Point(350, 400), croppedImg);

	// cropping with a cv::Rect that is then applied to the input image
	cv::Rect r(338, 388, 25, 25);
	cv::Mat rectImg = inputImg(r);

	cv::imshow("Original image", inputImg);
	cv::imshow("Cropped rectangle image", croppedImg);
	cv::imshow("Cropped with Rect image", rectImg);
	cv::waitKey(0);
}