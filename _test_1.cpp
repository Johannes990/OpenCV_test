#include <opencv2/opencv.hpp>
#include "opencv_test.h"


int get_ge_min(const int& min, const int& input) {
	int returnVal = input;

	if (returnVal < min) {
		returnVal = min;
	}

	return returnVal;
}

int get_odd_ge_min(const int& min, const int& input) {
	int localMin = min;

	if (min % 2 == 0) {
		localMin++;
	}

	int returnVal = get_ge_min(localMin, input);

	if (returnVal % 2 == 0) {
		returnVal++;
	}

	return returnVal;
}

void run_test_1() {
	const int maxPictureSize = 1200;
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn1.jpg", cv::IMREAD_COLOR);
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn2.jpg", cv::IMREAD_COLOR);
	cv::Mat img3 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\torn3.jpg", cv::IMREAD_COLOR);
	cv::Mat downscaleImg1 = downscale_image(img1, maxPictureSize);
	cv::Mat downscaleImg2 = downscale_image(img2, maxPictureSize);
	cv::Mat downscaleImg3 = downscale_image(img3, maxPictureSize);
	cv::Mat grayImg1, grayImg2, grayImg3, harris1, harris2, harris3, out1, out2, out3;
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
	// to rescale, set rows first, then columns
	cv::Mat croppedImg1 = downscaleImg1(cv::Range(r1StartY, r1EndY), cv::Range(r1StartX, r1EndX));
	cv::Mat croppedImg2 = downscaleImg2(cv::Range(r2StartY, r2EndY), cv::Range(r2StartX, r2EndX));
	cv::Mat croppedImg3 = downscaleImg3(cv::Range(r3StartY, r3EndY), cv::Range(r3StartX, r3EndX));
	int harrisValueMultiplier = 1;
	int harrisKSize = 3;
	int harrisBlockSize = 3;
	int harrisFreeParam = 1;
	double harrisValue = 0.0001;
	double harrisFree = 0.0002;

	cv::namedWindow("cropped Im1", cv::WINDOW_NORMAL);
	cv::namedWindow("cropped Im2", cv::WINDOW_NORMAL);
	cv::namedWindow("cropped Im3", cv::WINDOW_NORMAL);
	cv::namedWindow("main", cv::WINDOW_NORMAL);
	cv::imshow("cropped Im1", croppedImg1);
	cv::imshow("cropped Im2", croppedImg2);
	cv::imshow("cropped Im3", croppedImg3);

	cv::createTrackbar("thresh", "main", &harrisValueMultiplier, 500);
	cv::createTrackbar("k size", "main", &harrisKSize, 10);
	cv::createTrackbar("Block size", "main", &harrisBlockSize, 10);
	cv::createTrackbar("Harris free", "main", &harrisFreeParam, 500);
	cv::cvtColor(croppedImg1, grayImg1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(croppedImg2, grayImg2, cv::COLOR_BGR2GRAY);
	cv::cvtColor(croppedImg3, grayImg3, cv::COLOR_BGR2GRAY);

	while (true) {
		out1 = croppedImg1.clone();
		out2 = croppedImg2.clone();
		out3 = croppedImg3.clone();

		int ch = cv::waitKey(10);

		if ((char)ch == 'q') {
			break;
		}

		if ((char)ch == 'd') {
			double kFree = harrisFree * harrisFreeParam;
			double harrisThresh = harrisValue * harrisValueMultiplier;
			int normHarrisKSize = get_odd_ge_min(3, harrisKSize);
			harrisBlockSize = get_ge_min(1, harrisBlockSize);

			cv::cornerHarris(grayImg1, harris1, harrisBlockSize, normHarrisKSize, kFree);
			cv::cornerHarris(grayImg2, harris2, harrisBlockSize, normHarrisKSize, kFree);
			cv::cornerHarris(grayImg3, harris3, harrisBlockSize, normHarrisKSize, kFree);

			for (int i = 0; i < croppedImg1.cols; i++) {
				for (int j = 0; j < croppedImg1.rows; j++) {
					cv::Point p = cv::Point(i, j);

					if (harris1.at<float>(p) > harrisThresh) {
						cv::circle(out1, p, 2, cornerColor, cv::FILLED);
					}
				}
			}

			for (int i = 0; i < croppedImg2.cols; i++) {
				for (int j = 0; j < croppedImg2.rows; j++) {
					cv::Point p = cv::Point(i, j);

					if (harris2.at<float>(p) > harrisThresh) {
						cv::circle(out2, p, 2, cornerColor, cv::FILLED);
					}
				}
			}

			for (int i = 0; i < croppedImg3.cols; i++) {
				for (int j = 0; j < croppedImg3.rows; j++) {
					cv::Point p = cv::Point(i, j);

					if (harris3.at<float>(p) > harrisThresh) {
						cv::circle(out3, p, 1, cornerColor, cv::FILLED);
					}
				}
			}

			cv::imshow("cropped Im1", out1);
			cv::imshow("cropped Im2", out2);
			cv::imshow("cropped Im3", out3);
		}
	}
}