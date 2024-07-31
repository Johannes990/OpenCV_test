#include <opencv2/opencv.hpp>
#include "opencv_test.h"

void run_lines_contours() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat contoursLinesImg, cannyOut;
	cv::Mat	thresholded, grayscale, bilatFilterImg;
	cv::Scalar contourColor = cv::Scalar(30, 220, 200);
	cv::Scalar lineColor = cv::Scalar(150, 30, 200);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	int thresThres = 50.0;
	const int threshMaxVal = 255;
	int findContourMode = 1;
	int cannyThresh1 = 80;
	int cannyThresh2 = 240;
	int cannyAperture = 3;
	int bilatD = 3;
	int bilatSigma = 10;

	cv::namedWindow("Selected Image", cv::WINDOW_NORMAL);
	cv::namedWindow("contours and canny lines", cv::WINDOW_NORMAL);

	cv::imshow("Selected Image", inputImg);

	cv::cvtColor(inputImg, grayscale, cv::COLOR_BGR2GRAY);
	cv::createTrackbar("THR_thr", "contours and canny lines", &thresThres, 255.0);
	cv::createTrackbar("CON_mode", "contours and canny lines", &findContourMode, 3);
	cv::createTrackbar("CANNY_th1", "contours and canny lines", &cannyThresh1, 500);
	cv::createTrackbar("CANNY_th2", "contours and canny lines", &cannyThresh2, 1500);
	cv::createTrackbar("CANNY_APR", "contours and canny lines", &cannyAperture, 7);
	cv::createTrackbar("BILAT_D", "contours and canny lines", &bilatD, 15);
	cv::createTrackbar("BILAT_S", "contours and canny lines", &bilatSigma, 30);

	while (true) {
		contoursLinesImg = cv::Mat::zeros(inputImg.size(), CV_8UC3);

		if (cannyAperture < 3) {
			cannyAperture = 3;
		}

		int key = cv::waitKey(5);

		if ((char)key == 'q') {
			break;
		}

		if ((char)key == 'd') {
			cv::bilateralFilter(inputImg, bilatFilterImg, bilatD, bilatSigma, bilatSigma);
			//cv::threshold(grayscale, thresholded, thresThres, threshMaxVal, cv::THRESH_BINARY);
			
			cv::Canny(bilatFilterImg, cannyOut, cannyThresh1, cannyThresh2, cannyAperture);
			cv::findContours(cannyOut, contours, hierarchy, findContourMode, cv::CHAIN_APPROX_SIMPLE);
			cv::drawContours(contoursLinesImg, contours, -1, contourColor, 1);

			cv::imshow("contours and canny lines", cannyOut);
		}
	}

	cv::destroyAllWindows();
}