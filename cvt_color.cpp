#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_cvt_color() {
	cv::Mat bgr = cv::Mat(cv::Size(5, 5), CV_8UC3, cv::Scalar(50, 50, 78));
	cv::Mat out;

	cv::namedWindow("Original color space image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Converted color space", cv::WINDOW_GUI_NORMAL);

	std::cout << bgr.size() << ' ' << bgr.depth() << std::endl;

	// there is a lot of different conversion options...
	cv::cvtColor(bgr, out, cv::COLOR_BGR2HLS);

	std::cout << out.size() << ' ' << out.depth() << std::endl;
	std::cout << bgr << std::endl;
	std::cout << out << std::endl;

	cv::imshow("Original color space image", bgr);
	cv::imshow("Converted color space", out);

	cv::waitKey(0);
}