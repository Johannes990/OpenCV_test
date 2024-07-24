#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_named_window() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\linnapilt.jpg", cv::IMREAD_COLOR);

	// window flags
	// cv::WINDOW_NORMAL - can resize, also switch to fullscreen
	// cv::WINDOW_AUTOSIZE - cannot resize, fixed img size
	// cv::WINDOW_OPENGL - window with opengl support
	// cv::WINDOW_FULLSCREEN - cannot resize, can change the window to fullscreen
	// cv::WINDOW_FREERATIO - image can expand upon resize as much as wanted
	// cv::WINDOW_KEEPRATIO - ratio of the image is respected
	// cv::WINDOW_GUI_EXPANDED - status bar and tool bar
	// cv::WINDOW_GUI_NORMAL - old way of showing window
	cv::namedWindow("Img", cv::WINDOW_AUTOSIZE);

	cv::imshow("Img", img);

	cv::waitKey(0);
}