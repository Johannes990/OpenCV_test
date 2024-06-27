#include <opencv2\opencv.hpp>


void run_resize() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat resized;

	cv::namedWindow("initial", 0);
	cv::namedWindow("resized", 0);

	// this function decimates the input image by reciprocal values given in dx, dy, or in the Size()
	cv::resize(img, resized, cv::Size(192, 64), 0.0, 0.0);

	cv::imshow("initial", img);
	cv::imshow("resized", resized);
	cv::waitKey(0);
}