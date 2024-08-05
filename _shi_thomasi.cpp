#include <opencv2/opencv.hpp>
#include "opencv_test.h"


cv::Mat shi_thomasi(cv::Mat &img, int maxCorners = 10, double minQuality = 0.01, double minDistance = 10) {
	cv::Mat gray, corners;

	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::goodFeaturesToTrack(gray, corners, maxCorners, minQuality, minDistance);

	for (int i = 0; i < corners.cols; i++) {
		for (int j = 0; j < corners.rows; j++) {
			cv::circle(img, cv::Point(i, j), 3, cv::Scalar(0, 255, 255), cv::FILLED);
		}
	}
}

void run_shi_thomasi() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn1.jpg", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn2.jpg", cv::IMREAD_COLOR);
	cv::Mat img3 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn3.jpg", cv::IMREAD_COLOR);
	
	shi_thomasi(img1);
	shi_thomasi(img2);
	shi_thomasi(img3);

	cv::namedWindow("1", cv::WINDOW_NORMAL);
	cv::namedWindow("2", cv::WINDOW_NORMAL);
	cv::namedWindow("3", cv::WINDOW_NORMAL);

	cv::imshow("1", img1);
	cv::imshow("2", img2);
	cv::imshow("3", img3);

	cv::waitKey(0);
}