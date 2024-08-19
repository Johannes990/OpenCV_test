#include <opencv2/opencv.hpp>
#include "opencv_test.h"


struct ColorDist {
	bool operator()(const cv::Vec3b& a, const cv::Vec3b& b) {
		return cv::norm(a, b) > 65;	// experimental value
	}
};

void run_partition() {
	std::vector<int> labels;
}