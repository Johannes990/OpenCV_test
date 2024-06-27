#include <opencv2\opencv.hpp>
#include "opencv_test.h"

void run_affine_transform() {
	// some animation :)
	int count = 1;
	while (count++) {
		cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
		cv::Mat outputImg = cv::Mat::zeros(cv::Size(inputImg.cols, inputImg.rows), inputImg.type());
		cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
		cv::namedWindow("Transformed image", cv::WINDOW_GUI_NORMAL);

		cv::Point2f inputMatrix[3];
		cv::Point2f outputMatrix[3];

		inputMatrix[0] = cv::Point2f(0.0, 0.0);
		inputMatrix[1] = cv::Point2f(inputImg.cols, 0.0);
		inputMatrix[2] = cv::Point2f(inputImg.cols, inputImg.rows);

		outputMatrix[0] = cv::Point2f(400 - count / 2.0, 200);
		outputMatrix[1] = cv::Point2f(600, 200 + count);
		outputMatrix[2] = cv::Point2f(400, 400 - count);

		cv::Mat transformMatrix = cv::getAffineTransform(inputMatrix, outputMatrix);
		cv::warpAffine(inputImg, outputImg, transformMatrix, outputImg.size());

		cv::imshow("Original image", inputImg);
		cv::imshow("Transformed image", outputImg);
		
		int ch = cv::waitKey(1);
		if ((char)ch == 'Q') {
			break;
		}
	}
	
}