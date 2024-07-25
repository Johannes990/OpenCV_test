#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_destroy_window() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);

	cv::namedWindow("Window1", cv::WINDOW_NORMAL);
	cv::namedWindow("Window2", cv::WINDOW_NORMAL);
	cv::namedWindow("Window3", cv::WINDOW_NORMAL);
	cv::namedWindow("Window4", cv::WINDOW_NORMAL);

	cv::imshow("Window1", img);
	cv::imshow("Window2", img);
	cv::imshow("Window3", img);
	cv::imshow("Window4", img);

	// kill single window
	cv::waitKey(0);
	cv::destroyWindow("Window1");

	// --//--
	cv::waitKey(0);
	cv::destroyWindow("Window2");

	// kill all remaining windows
	cv::waitKey(0);
	cv::destroyAllWindows();

	cv::waitKey(0);
}