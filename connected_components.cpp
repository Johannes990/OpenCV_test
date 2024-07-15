#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_connected_components() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	cv::Mat labels;
	

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(img, img, 100, 255, cv::THRESH_BINARY);

	int componentsCount = cv::connectedComponents(img, labels, 8);

	std::vector<cv::Vec3b> colors(componentsCount);

	for (int i = 0; i < componentsCount; i++) {
		colors[i] = cv::Vec3b(200 - (10 * i), 0, 15 * i);
	}

	for (int i = 0; i < img.cols; i++) {
		for (int j = 0; j < img.rows; j++) {
			cv::Point p = cv::Point(i, j);

			if (labels.at<int>(p) != 0) {
				out.at<cv::Vec3b>(p) = colors[(int)labels.at<int>(p)];
			}
			
		}
	}

	cv::imshow("In", img);
	cv::imshow("Out", out);

	cv::waitKey(0);
}
