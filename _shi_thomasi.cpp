#include <opencv2/opencv.hpp>
#include "opencv_test.h"


cv::Mat shi_thomasi(cv::Mat &img, int maxCorners = 10, double minQuality = 0.01, double minDistance = 10) {
	cv::Mat gray, corners;
	cv::Mat returnImg = img.clone();

	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::goodFeaturesToTrack(gray, corners, maxCorners, minQuality, minDistance);

	for (int i = 0; i < corners.rows; i++) {
		cv::Vec2f cPoint = corners.at<cv::Vec2f>(cv::Point(0, i));
		int xCoord = cPoint[0];
		int yCoord = cPoint[1];
		cv::Point center = cv::Point(xCoord, yCoord);
		cv::circle(returnImg, center, 6, cv::Scalar(0, 255, 200), cv::FILLED);
	}

	return returnImg;
}

void run_shi_thomasi() {
	const int maxPictureSize = 1200;
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn1.jpg", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn2.jpg", cv::IMREAD_COLOR);
	cv::Mat img3 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn3.jpg", cv::IMREAD_COLOR);
	cv::Mat downscaleImg1 = downscale_image(img1, maxPictureSize);
	cv::Mat downscaleImg2 = downscale_image(img2, maxPictureSize);
	cv::Mat downscaleImg3 = downscale_image(img3, maxPictureSize);
	cv::Mat stImg1, stImg2, stImg3;
	int r1StartX, r1StartY, r2StartX, r2StartY, r3StartX, r3StartY,
		r1EndX, r1EndY, r2EndX, r2EndY, r3EndX, r3EndY;
	cv::Rect r1 = cv::selectROI(downscaleImg1, true, false);
	cv::Rect r2 = cv::selectROI(downscaleImg2, true, false);
	cv::Rect r3 = cv::selectROI(downscaleImg3, true, false);
	cv::Rect r1Norm = normalize_rect(r1);
	cv::Rect r2Norm = normalize_rect(r2);
	cv::Rect r3Norm = normalize_rect(r3);
	cv::Scalar cornerColor = cv::Scalar(50, 255, 255);
	r1StartX = r1Norm.x;
	r1StartY = r1Norm.y;
	r1EndX = r1Norm.x + r1Norm.width;
	r1EndY = r1Norm.y + r1Norm.height;
	r2StartX = r2Norm.x;
	r2StartY = r2Norm.y;
	r2EndX = r2Norm.x + r2Norm.width;
	r2EndY = r2Norm.y + r2Norm.height;
	r3StartX = r3Norm.x;
	r3StartY = r3Norm.y;
	r3EndX = r3Norm.x + r3Norm.width;
	r3EndY = r3Norm.y + r3Norm.height;
	cv::Mat croppedImg1 = downscaleImg1(cv::Range(r1StartY, r1EndY), cv::Range(r1StartX, r1EndX));
	cv::Mat croppedImg2 = downscaleImg2(cv::Range(r2StartY, r2EndY), cv::Range(r2StartX, r2EndX));
	cv::Mat croppedImg3 = downscaleImg3(cv::Range(r3StartY, r3EndY), cv::Range(r3StartX, r3EndX));
	int maxCorners = 100;
	double minQuality = 0.0001;
	int minQualityMultiplier = 100;
	int minDistance = 100;

	cv::namedWindow("1", cv::WINDOW_NORMAL);
	cv::namedWindow("2", cv::WINDOW_NORMAL);
	cv::namedWindow("3", cv::WINDOW_NORMAL);

	cv::namedWindow("main", cv::WINDOW_NORMAL);

	cv::createTrackbar("MAXCorner", "main", &maxCorners, 200);
	cv::createTrackbar("MIN Q", "main", &minQualityMultiplier, 1000);
	cv::createTrackbar("MIN D", "main", &minDistance, 250);

	while (true) {
		int ch = cv::waitKey(10);

		if ((char)ch == 'q') {
			break;
		}

		if ((char)ch == 'd') {
			double q = minQuality * minQualityMultiplier;
			stImg1 = shi_thomasi(croppedImg1, maxCorners, q, minDistance);
			stImg2 = shi_thomasi(croppedImg2, maxCorners, q, minDistance);
			stImg3 = shi_thomasi(croppedImg3, maxCorners, q, minDistance);

			cv::imshow("1", stImg1);
			cv::imshow("2", stImg2);
			cv::imshow("3", stImg3);
		}
	}
}