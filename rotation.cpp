#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_rotation() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg");
	cv::Mat rotatedImg = cv::Mat::zeros(cv::Size(inputImg.cols, inputImg.rows), inputImg.type());
	int angle = 115.0;
	double scale = 1.0;
	cv::Point2f center(inputImg.cols / 2.0, inputImg.rows / 2.0);

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::imshow("Original image", inputImg);

	while (angle++) {
		cv::namedWindow("Rotated image", cv::WINDOW_GUI_NORMAL);

		cv::Mat rotMatrix = cv::getRotationMatrix2D(center, angle, scale);

		cv::warpAffine(inputImg, rotatedImg, rotMatrix, inputImg.size());

		cv::imshow("Rotated image", rotatedImg);
		cv::waitKey(1);
	}
}