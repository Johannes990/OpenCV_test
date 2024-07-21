#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_green_detection_mask() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat hsvImg;
	cv::Mat greenMask;
	cv::Mat notGreenMask;
	cv::Mat grayImg;
	cv::Mat maskedGrayImg;
	cv::Mat cornerEigenResponse;
	const int blockSize = 3;
	const int kSize = 3;

	// converting to hue and saturation based colormap to better separate green hues
	cv::cvtColor(img, hsvImg, cv::COLOR_BGR2HSV);

	// green space mask and inversion - not green -> 1, green -> 0
	// hue:			35 - 80 should be the green hue range
	// saturation:	40 - 255 to avoid very lihgt greens closer to white
	// value:		40 - 255 to avoid very dark regions that might be shadows
	cv::inRange(hsvImg, cv::Scalar(35, 40, 40), cv::Scalar(85, 255, 255), greenMask);
	cv::bitwise_not(greenMask, notGreenMask);

	// applying mask
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	grayImg.copyTo(maskedGrayImg, notGreenMask);
	cv::Mat responseExtract = cv::Mat::zeros(maskedGrayImg.size(), CV_32FC1);

	cv::cornerEigenValsAndVecs(maskedGrayImg, cornerEigenResponse, blockSize, kSize, cv::BORDER_DEFAULT);

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
	double treshold = 0.1 * maxVal;	// 

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", maskedGrayImg);

	cv::waitKey(0);
}