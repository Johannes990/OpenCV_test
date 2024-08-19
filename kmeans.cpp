#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_kmeans() {
	const int K = 3;								// cluster count
	const int dataSize = 100;						// data points count
	cv::Mat data = cv::Mat(dataSize, 2, CV_32F);	// 100 (x, y) tuples for data example
	cv::Mat labels, centers;
	cv::TermCriteria criteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, dataSize, 0.2);
	

	cv::RNG rng = cv::theRNG();
	rng.fill(data, cv::RNG::UNIFORM, 0, 1); // populate our data with random floats in range [0, 1)

	std::cout << data << std::endl;
}