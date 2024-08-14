#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_reduce() {
	const std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\10_08_2024\\IMG_20240806_142444.jpg";
	cv::Mat img = cv::imread(filename, cv::IMREAD_COLOR);

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	cv::imshow("In", img);

	cv::waitKey(0);
}
