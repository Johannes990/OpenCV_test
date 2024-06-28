#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_remap() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat outputImg = cv::Mat::zeros(inputImg.size(), inputImg.type());
	cv::Mat mapX = cv::Mat::zeros(inputImg.size(), CV_32FC1);
	cv::Mat mapY = cv::Mat::zeros(inputImg.size(), CV_32FC1);

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Remapped image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Map X", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Map Y", cv::WINDOW_GUI_NORMAL);

	for (int i = 0; i < inputImg.cols; i++) {
		for(int j = 0; j < inputImg.rows; j++) {
			if (i < 500 && j < 500) {
				mapX.at<float>(cv::Point(i, j)) = inputImg.cols - i; // here we flip the original image in the x axis
				mapY.at<float>(cv::Point(i, j)) = inputImg.rows - j; // and flip it in the y axis
			}
		}
	}

	cv::remap(inputImg, outputImg, mapX, mapY, cv::INTER_CUBIC);
	mapX.convertTo(mapX, CV_8UC1);
	mapY.convertTo(mapY, CV_8UC1);

	cv::imshow("Original image", inputImg);
	cv::imshow("Remapped image", outputImg);
	cv::imshow("Map X", mapX);
	cv::imshow("Map Y", mapY);
	cv::waitKey(0);
}