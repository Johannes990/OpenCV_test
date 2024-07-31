#include <opencv2/opencv.hpp>
#include "opencv_test.h"

void run_lines_contours() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\aken1.jpg", cv::IMREAD_COLOR);
	cv::Mat contoursLinesImg, cannyOut, grayscale, bilatFilterImg, sobelDx, sobelDy, sobelGray;
	cv::Scalar contourColor = cv::Scalar(30, 220, 200);
	cv::Scalar lineColor = cv::Scalar(150, 30, 200);

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	std::vector<cv::Vec4i> houghLines;

	int findContourMode = 1;
	int cannyThresh1 = 80;
	int cannyThresh2 = 240;
	const int cannyAperture = 3;
	const int bilatD = 5;
	int bilatSigma = 10;
	int contourArea = 100;
	int houghThreshold = 50;
	int minLineLength = 100;
	int maxLineGap = 100;
	int houghRho = 1.0;
	double houghTheta = CV_PI / 180;

	cv::namedWindow("Selected Image", cv::WINDOW_NORMAL);
	cv::namedWindow("contours and canny lines", cv::WINDOW_NORMAL);

	cv::imshow("Selected Image", inputImg);

	cv::cvtColor(inputImg, grayscale, cv::COLOR_BGR2GRAY);
	
	cv::createTrackbar("CON_mode", "contours and canny lines", &findContourMode, 3);
	cv::createTrackbar("CANNY_th1", "contours and canny lines", &cannyThresh1, 500);
	cv::createTrackbar("CANNY_th2", "contours and canny lines", &cannyThresh2, 1500);
	cv::createTrackbar("BILAT_S", "contours and canny lines", &bilatSigma, 30);
	cv::createTrackbar("CONT_A", "contours and canny lines", &contourArea, 1500);
	cv::createTrackbar("HOUGH_RO", "contours and canny lines", &houghRho, 150);
	cv::createTrackbar("HOUGH_TH", "contours and canny lines", &houghThreshold, 200);
	cv::createTrackbar("HOUGH_LL", "contours and canny lines", &minLineLength, 600);
	cv::createTrackbar("HOUGH_LG", "contours and canny lines", &maxLineGap, 200);

	while (true) {
		contoursLinesImg = cv::Mat::zeros(inputImg.size(), CV_8UC3);

		int key = cv::waitKey(5);

		if ((char)key == 'q') {
			break;
		}

		if ((char)key == 'h') {
			cv::HoughLinesP(cannyOut, houghLines, houghRho, houghTheta, houghThreshold, minLineLength, maxLineGap);

			for (int i = 0; i < houghLines.size(); i++) {
				cv::Point start = cv::Point(houghLines[i][0], houghLines[i][1]);
				cv::Point end = cv::Point(houghLines[i][2], houghLines[i][3]);

				cv::line(contoursLinesImg, start, end, lineColor, 2);
			}
			cv::imshow("contours and canny lines", contoursLinesImg);
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
			
			int key2 = cv::waitKey(1000);

			if ((char)key2 == 's') {
				cv::cvtColor(contoursLinesImg, sobelGray, cv::COLOR_BGR2GRAY);
				cv::Sobel(sobelGray, sobelDx, CV_8UC1, 1, 0, 3, 1.0, 1.0);
				cv::Sobel(sobelGray, sobelDy, CV_8UC1, 0, 1, 3, 1.0, 1.0);

				cv::imshow("Sobel dy", sobelDy);
				cv::imshow("Sobel dx", sobelDx);
			}

			if ((char)key2 == 'c') {
				continue;
			}
		}
	}

	cv::destroyAllWindows();
}