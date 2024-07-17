#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_canny() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat out;
	cv::Mat out2;
	double threshold1 = 80.0;	// anecdotal evidence suggests to use
	double threshold2 = 240.0;	// as threshold2 value 3x threshold1 value, like here
	double threshold3 = 900.0;

	cv::Canny(img, out, threshold1, threshold2);
	cv::Canny(img, out2, 300, threshold3);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out2", cv::WINDOW_GUI_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", out);
	cv::imshow("Out2", out2);

	cv::waitKey(0);
}