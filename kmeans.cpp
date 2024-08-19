#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_kmeans() {
	const int K = 3;								// cluster count
	const int dataSize = 100;						// data points count
	const int screenX = 500;
	const int screenY = 500;
	const int pointRadius = 3;
	const cv::Scalar firstColor(0, 255, 255);
	const cv::Scalar secondColor(255, 255, 0);
	const cv::Scalar thirdColor(255, 0, 255);
	cv::Mat data = cv::Mat(dataSize, 2, CV_32F);	// 100 (x, y) tuples for data example
	cv::Mat labels, centers;
	cv::TermCriteria criteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, dataSize, 0.2);
	
	cv::theRNG().state = cv::getTickCount();
	cv::RNG rng = cv::theRNG();
	rng.fill(data, cv::RNG::UNIFORM, 0, 1); // populate our data with random floats in range [0, 1)

	cv::kmeans(data, K, labels, criteria, 3, cv::KMEANS_RANDOM_CENTERS, centers);

	// visualize kmeans output
	cv::Mat img(screenX, screenY, CV_8UC3, cv::Scalar::all(255));

	for (int i = 0; i < dataSize; i++) {
		int clusterId = labels.at<int>(i);
		cv::Point dataPoint(data.at<float>(i, 0) * screenX, data.at<float>(i, 1) * screenY);

		if (clusterId == 0) {
			cv::circle(img, dataPoint, pointRadius, firstColor, cv::FILLED);
		} else if (clusterId == 1) {
			cv::circle(img, dataPoint, pointRadius, secondColor, cv::FILLED);
		} else if (clusterId == 2) {
			cv::circle(img, dataPoint, pointRadius, thirdColor, cv::FILLED);
		}

	}

	cv::imshow("output", img);
	cv::waitKey(0);

	std::cout << data << std::endl;
}