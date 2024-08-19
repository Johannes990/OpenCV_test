#include <opencv2/opencv.hpp>
#include "opencv_test.h"


struct ColorDist {
	bool operator()(const cv::Vec3b& a, const cv::Vec3b& b) {
		return cv::norm(a, b) > 100;	// experimental value
	}
};

void run_partition() {
	std::vector<int> labels;
	std::vector<cv::Vec3f> data;
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\partition.png", cv::IMREAD_COLOR);

	// resixe image to take less time
	//cv::resize(img, img, cv::Size(), 0.5, 0.5);

	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	std::cout << img.total() << " pixels" << std::endl;

	// pack image into a vector
	data.insert(data.begin(), img.begin<cv::Vec3b>(), img.end<cv::Vec3b>());

	int k = cv::partition(data, labels, ColorDist());

	std::cout << "Label count: " << k << std::endl;

	cv::imshow("Out", img);
	cv::waitKey(0);
}