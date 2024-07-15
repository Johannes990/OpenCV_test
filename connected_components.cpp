#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_connected_components() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	cv::Mat labels;
	std::vector<cv::Vec3b> colors;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);

	int componentsCount = cv::connectedComponents(img, labels, 8);

	

	for (int i = 0; i < componentsCount; i++) {
		if (i == 0) {
			colors[i] = cv::Vec3b(0, 0, 0);
		}
		else {
			colors[i] = cv::Vec3b(10 * i, 0, 15 * i);
		}
	}


	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}
