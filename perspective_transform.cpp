#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_perspective_transform() {
	std::vector<cv::Point3f> inputMatrix;
	std::vector<cv::Point3f> outputMatrix;
	std::vector<cv::Point2f> imgPoints;
	std::vector<cv::Point2f> imgTransformPoints;
	cv::Mat img = cv::Mat::zeros(500, 500, CV_8UC3);
	const cv::Scalar imgPointColor = cv::Scalar(0, 255, 0);
	const cv::Scalar transformPointColor = cv::Scalar(255, 0, 255);
	const int radius = 4;

	inputMatrix.push_back(cv::Point3f(25, 35, 45));
	inputMatrix.push_back(cv::Point3f(35, 34, 45));
	inputMatrix.push_back(cv::Point3f(45, 33, 45));
	inputMatrix.push_back(cv::Point3f(55, 32, 45));
	inputMatrix.push_back(cv::Point3f(65, 31, 45));
	inputMatrix.push_back(cv::Point3f(75, 30, 45));
	inputMatrix.push_back(cv::Point3f(85, 29, 45));
	inputMatrix.push_back(cv::Point3f(95, 28, 45));
	inputMatrix.push_back(cv::Point3f(105, 27, 45));

	imgPoints.push_back(cv::Point2f(150, 150));
	imgPoints.push_back(cv::Point2f(150, 300));
	imgPoints.push_back(cv::Point2f(300, 300));
	imgPoints.push_back(cv::Point2f(300, 150));
	
	cv::Mat transformMatrix = (cv::Mat_<float>(4, 4) << 1.0, 1.0, 1.0, 1.0,
														  1.5, 0.5, 1.5, 1.0,
														  0.5, 1.0, 1.0, 0.5,
														  1.0, 1.0, 3.5, 2.5);
	cv::Mat imgTransformMat = (cv::Mat_<float>(3, 3) << 0, 1, 0,
														1, 0, 0,
														0, 0, 1);


	std::cout << "Input matrix is:\n" << std::endl;
	std::cout << inputMatrix << std::endl;
	std::cout << "\nTransformation matrix is:\n" << std::endl;
	std::cout << transformMatrix << std::endl;

	cv::perspectiveTransform(inputMatrix, outputMatrix, transformMatrix);
	cv::perspectiveTransform(imgPoints, imgTransformPoints, imgTransformMat);

	std::cout << "\nThe output matrix is:\n" << std::endl;
	std::cout << outputMatrix << std::endl;

	for (int i = 0; i < imgPoints.size(); i++) {
		cv::circle(img, imgPoints[i], radius, imgPointColor, cv::FILLED);
		cv::circle(img, imgTransformPoints[i], radius, transformPointColor);
	}

	cv::namedWindow("Img", cv::WINDOW_NORMAL);
	cv::imshow("Img", img);
	cv::waitKey(0);
}