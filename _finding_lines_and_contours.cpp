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

	int findContourMode = 1;
	int cannyThresh1 = 80;
	int cannyThresh2 = 240;
	const int cannyAperture = 3;
	const int bilatD = 5;
	int bilatSigma = 10;
	int contourArea = 100;

	cv::namedWindow("Selected Image", cv::WINDOW_NORMAL);
	cv::namedWindow("contours and canny lines", cv::WINDOW_NORMAL);

	cv::imshow("Selected Image", inputImg);

	cv::cvtColor(inputImg, grayscale, cv::COLOR_BGR2GRAY);
	
	cv::createTrackbar("CON_mode", "contours and canny lines", &findContourMode, 3);
	cv::createTrackbar("CANNY_th1", "contours and canny lines", &cannyThresh1, 500);
	cv::createTrackbar("CANNY_th2", "contours and canny lines", &cannyThresh2, 1500);
	cv::createTrackbar("BILAT_S", "contours and canny lines", &bilatSigma, 30);
	cv::createTrackbar("CONT_A", "contours and canny lines", &contourArea, 15000);

	while (true) {
		contoursLinesImg = cv::Mat::zeros(inputImg.size(), CV_8UC3);

		int key = cv::waitKey(5);

		if ((char)key == 'q') {
			break;
		}

		if ((char)key == 'd') {
			cv::bilateralFilter(inputImg, bilatFilterImg, bilatD, bilatSigma, bilatSigma);
			
			cv::Canny(bilatFilterImg, cannyOut, cannyThresh1, cannyThresh2, cannyAperture);
			cv::findContours(cannyOut, contours, hierarchy, findContourMode, cv::CHAIN_APPROX_SIMPLE);

			for (int i = 0; i < contours.size(); i++) {
				int area = cv::contourArea(contours[i]);
				if (area > contourArea) {
					cv::drawContours(contoursLinesImg, contours, i, contourColor, 1);
				}
			}

			cv::imshow("contours and canny lines", contoursLinesImg);
		}
	}

	cv::destroyAllWindows();
}