#include <opencv2/opencv.hpp>
#include "opencv_test.h"


struct ColorDist {
	bool operator()(const cv::Vec3b& a, const cv::Vec3b& b) {
		return cv::norm(a, b) < 50;	// experimental value
	}
};

void run_partition() {
	std::vector<int> labels;
	std::vector<cv::Vec3f> data;
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\4colors.png", cv::IMREAD_COLOR);

	// resixe image to take less time
	// cv::resize(img, img, cv::Size(), 0.5, 0.5);
	// std::cout << img.total() << " pixels" << std::endl;

	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	// pack image into a vector
	data.insert(data.begin(), img.begin<cv::Vec3b>(), img.end<cv::Vec3b>());

	int k = cv::partition(data, labels, ColorDist());

	std::cout << "Label count: " << k << std::endl;
	std::cout << labels.size() << " labels" << std::endl;

	for (int i = 0; i < labels.size(); i++) {
		if (labels[i] == 4) {
			img.at<cv::Vec3b>(cv::Point(i % img.cols, i / img.cols)) = cv::Vec3b(0, 100, 0);
		}
	}

	cv::imshow("Out", img);
	cv::waitKey(0);
}