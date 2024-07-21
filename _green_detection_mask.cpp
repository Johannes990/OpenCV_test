#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_green_detection_mask() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat hsvImg;
	cv::Mat greenMask;
	cv::Mat notGreenMask;
	cv::Mat grayImg;
	cv::Mat maskedGrayImg;
	cv::Mat bilatFilteredImg;
	cv::Mat cornerEigenResponse;
	cv::Mat dilatedImg;
	cv::Mat outputImgWithCorners;
	const cv::Scalar cornerColor = cv::Scalar(50, 50, 255);
	const int blockSize = 3;
	const int kSize = 3;
	const int cornerRadius = 3;
	const int cornerThickness = 1;

	// converting to hue and saturation based colormap to better separate green hues
	cv::cvtColor(img, hsvImg, cv::COLOR_BGR2HSV);

	// green space mask and inversion - not green -> 1, green -> 0
	// hue:			35 - 80 should be the green hue range
	// saturation:	40 - 255 to avoid very light greens closer to white
	// value:		40 - 255 to avoid very dark regions that might be shadows
	cv::Scalar filterValuesFrom = cv::Scalar(35, 40, 40);
	cv::Scalar filterValuesTo = cv::Scalar(80, 255, 255);
	cv::inRange(hsvImg, filterValuesFrom, filterValuesTo, greenMask);
	cv::bitwise_not(greenMask, notGreenMask);

	// applying mask
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	grayImg.copyTo(maskedGrayImg, notGreenMask);

	// try some filtering
	cv::GaussianBlur(maskedGrayImg, bilatFilteredImg, cv::Size(5, 5), 1.0, 1.0);

	cv::Mat responseExtract = cv::Mat::zeros(bilatFilteredImg.size(), CV_32FC1);
	cv::cornerEigenValsAndVecs(bilatFilteredImg, cornerEigenResponse, blockSize, kSize, cv::BORDER_DEFAULT);

	// corner response extraction
	for (int i = 0; i < cornerEigenResponse.rows; i++) {
		for (int j = 0; j < cornerEigenResponse.cols; j++) {
			float lambda1 = cornerEigenResponse.at<cv::Vec6f>(i, j)[0];
			float lambda2 = cornerEigenResponse.at<cv::Vec6f>(i, j)[1];
			cornerEigenResponse.at<float>(i, j) = std::min(lambda1, lambda2);
		}
	}

	// thresholding
	double maxVal = 0.0;
	cv::minMaxLoc(cornerEigenResponse, nullptr, &maxVal);
	double threshold = 0.025 * maxVal;	// this value must be tested and some basis provided for its derivation
	cv::Mat strongCorners = (cornerEigenResponse > threshold);

	// non maximum suppression
	cv::dilate(cornerEigenResponse, dilatedImg, cv::Mat());
	cv::Mat localMax = (cornerEigenResponse == dilatedImg);
	cv::Mat finalCorners = cv::Mat::zeros(cornerEigenResponse.size(), CV_8UC1);

	for (int i = 0; i < cornerEigenResponse.rows; i++) {
		for (int j = 0; j < cornerEigenResponse.cols; j++) {
			if (localMax.at<uchar>(i, j) && cornerEigenResponse.at<float>(i, j) > threshold) {
				finalCorners.at<uchar>(i, j) = 255;
			}
		}
	}

	// show the picture with corners
	cv::cvtColor(grayImg, outputImgWithCorners, cv::COLOR_GRAY2BGR);
	cv::Point cornerPoint;

	for (int i = 0; i < finalCorners.rows; i++) {
		for (int j = 0; j < finalCorners.cols; j++) {
			if (finalCorners.at<uchar>(i, j) == 255) {
				cornerPoint = cv::Point(j, i);
				cv::circle(outputImgWithCorners, cornerPoint, cornerRadius, cornerColor, cornerThickness);
			}
		}
	}

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", outputImgWithCorners);

	cv::waitKey(0);
}