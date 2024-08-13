#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_mahalanobis() {
	std::srand(time(NULL));	// set a new random seed for rng
	
	const int xSize = 500;
	const int ySize = 500;
	cv::Mat input = cv::Mat::zeros(xSize, ySize, CV_8UC3);
	const std::vector<cv::Point> pointsGroup1 = {cv::Point(86, 150), cv::Point(112, 270),
										   cv::Point(117, 109), cv::Point(37, 271),
										   cv::Point(76, 100), cv::Point(12, 194),
										   cv::Point(400, 200), cv::Point(190, 40)};
	const std::vector<cv::Point> pointsGroup2 = {cv::Point(260, 376), cv::Point(495, 280),
										   cv::Point(345, 353), cv::Point(189, 380),
										   cv::Point(232, 283), cv::Point(197, 386),
										   cv::Point(200, 175), cv::Point(280, 31)};
	const cv::Scalar point1Color = cv::Scalar(25, 190, 190);
	const cv::Scalar point2Color = cv::Scalar(230, 0, 76);
	const int radius = 4;
	cv::Mat group1, mean1, covar1, group2, mean2, covar2;

	cv::namedWindow("points", cv::WINDOW_NORMAL);

	// STEP 1
	// besides showing points on the screen, we also assign them to a Mat
	for (int i = 0; i < pointsGroup1.size(); i++) {
		cv::circle(input, pointsGroup1[i], radius, point1Color, cv::FILLED);

		cv::Mat sample = cv::Mat(1, 2, CV_32FC1);
		sample.at<float>(0, 0) = pointsGroup1[i].x;
		sample.at<float>(0, 1) = pointsGroup1[i].y;
		group1.push_back(sample);
	}

	for (int i = 0; i < pointsGroup2.size(); i++) {
		cv::circle(input, pointsGroup2[i], radius, point2Color, cv::FILLED);

		cv::Mat sample = cv::Mat(1, 2, CV_32FC1);
		sample.at<float>(0, 0) = pointsGroup2[i].x;
		sample.at<float>(0, 1) = pointsGroup2[i].y;
		group2.push_back(sample);
	}

	// STEP 2
	// calculating the covariance matrix
	cv::calcCovarMatrix(group1, covar1, mean1, cv::COVAR_NORMAL | cv::COVAR_ROWS, CV_32F);
	cv::calcCovarMatrix(group2, covar2, mean2, cv::COVAR_NORMAL | cv::COVAR_ROWS, CV_32F);

	// STEP 3
	// adding new points and calculating the mahalanobis
	// which actually classifies the point according to the inputs given i.e. clustering
	while (true) {
		cv::Point randomPoint = cv::Point(std::rand() % xSize, std::rand() % ySize);
		cv::Mat pointSample = cv::Mat(1, 2, CV_32FC1);

		pointSample.at<float>(0, 0) = randomPoint.x;
		pointSample.at<float>(0, 1) = randomPoint.y;

		double distanceToPG1 = cv::Mahalanobis(pointSample, mean1, covar1);
		double distanceToPG2 = cv::Mahalanobis(pointSample, mean2, covar2);

		std::cout << "random point: " << randomPoint << std::endl;
		std::cout << "distance to the first cluster: " << distanceToPG1 << std::endl;
		std::cout << "distance to the second cluster: " << distanceToPG2 << std::endl;

		cv::imshow("points", input);
		if ((char)cv::waitKey(0) == 'q') {
			break;
		}

		if (distanceToPG1 >= distanceToPG2) {
			cv::circle(input, randomPoint, radius, point2Color, cv::FILLED);
		}
		else {
			cv::circle(input, randomPoint, radius, point1Color, cv::FILLED);
		}
	}

	std::cout << "Group 1:\n" << group1 << std::endl;
	std::cout << "Group 2:\n" << group2 << std::endl;
}