#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_corner_eigen_val_vect() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat imgGray;
	cv::Mat cornerMinEigenVal;
	cv::Mat cornerEigenValsAndVecs;	// this Mat will hold 6 values for every point
									// not sure how to use this, have to try
	const int blockSize = 3;
	const int kSize = 3;
	const int borderType = cv::BORDER_DEFAULT;
	const cv::Point checkPoint = cv::Point(25, 25);

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
	cv::cornerEigenValsAndVecs(imgGray, cornerEigenValsAndVecs, blockSize, kSize, borderType);
	cv::cornerMinEigenVal(imgGray, cornerMinEigenVal, blockSize, kSize, borderType);

	std::cout << "cornerMinEigenVal values at Point(" << checkPoint.x << ", " << checkPoint.y << "): " << cornerMinEigenVal.at<float>(checkPoint) << std::endl;
	std::cout << "cornerEigenValsAndVecs values at Point(" << checkPoint.x << ", " << checkPoint.y << "): " << cornerEigenValsAndVecs.at<cv::Vec6f>(checkPoint) << std::endl;

	cv::namedWindow("Corners", cv::WINDOW_GUI_NORMAL);

	for (int i = 0; i < img.cols; i++) {
		for (int j = 0; j < img.rows; j++) {
			cv::Point p = cv::Point(i, j);
			if (cornerMinEigenVal.at<float>(p) > 0.005) {
				cv::circle(img, p, 1, cv::Scalar(100, 100, 200), 1);
			}
		}
	}

	cv::imshow("Corners", img);

	cv::waitKey(0);
}