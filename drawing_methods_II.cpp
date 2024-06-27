#include <opencv2\opencv.hpp>
#include "opencv_test.h"
#include <string>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>


void run_drawing_methods_II() {
	int win_width = 1500;
	int win_height = 1500;
	cv::Mat frame = cv::Mat::zeros(cv::Size(win_height, win_height), CV_8UC3);
	cv::namedWindow("Frame", 0);

	std::string text = "Hello, text world!";
	std::string textToAdd = " Concatenating text on top.";
	cv::putText(frame, text, cv::Point(100, 100), cv::FONT_ITALIC, 1.0, cv::Scalar(150, 25, 75), 2, cv::LINE_4);

	// getTextSize() - this returns the size of the text in pixels on the screen
	int bL = 0;
	cv::Size textSize = cv::getTextSize(text, cv::FONT_ITALIC, 1.0, 2, &bL);

	std::cout << "text width is " << textSize.width << " pixels and text height is " << textSize.height << " pixels." << std::endl;

	// addText() - used to add text to stuff, uses Qt framework
	//cv::addText(frame, textToAdd, cv::Point(100 + textSize.width, 100), "Arial", 30, cv::Scalar(0, 255, 255), cv::QT_FONT_LIGHT);

	// fill area between points, convex
	std::vector<cv::Point> points = { cv::Point(300, 300), cv::Point(400, 300), cv::Point(350, 350) };
	cv::fillConvexPoly(frame, points, cv::Scalar(200, 200, 0), cv::LINE_AA);

	// fill area between points
	std::vector<std::vector<cv::Point>> objectPoints = {
		{cv::Point(400, 440), cv::Point(500, 600), cv::Point(600, 500)},
		{cv::Point(500, 540), cv::Point(600, 700), cv::Point(700, 600)},
		{cv::Point(600, 640), cv::Point(700, 800), cv::Point(800, 700)},
		{cv::Point(700, 740), cv::Point(800, 900), cv::Point(900, 800)},
	};
	cv::fillPoly(frame, objectPoints, cv::Scalar(0, 100, 255), cv::LINE_AA);

	// polylines
	cv::polylines(frame, objectPoints, false, cv::Scalar(133, 212, 231), 2, cv::LINE_AA);

	cv::imshow("Frame", frame);
	cv::waitKey(0);
}