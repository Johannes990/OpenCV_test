#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_corner_harris() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);
	cv::Mat imgGray, harris;
	cv::Mat out = cv::Mat::zeros(img.size(), CV_8UC3);
	const int blockSize = 2;	// neighborhood size
	const int kSize = 5;		// aperture parameter for the Sobel operator
	const double k = 0.005;		// Harris detector free parameter
	const int borderType = cv::BORDER_DEFAULT;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Corners", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Gray corners", cv::WINDOW_GUI_NORMAL);

	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);	// convert 3-channel image to single channel
	cv::cornerHarris(imgGray, harris, blockSize, kSize, k, borderType);

	// cornerHarris output is some small float value, so detected values are not visible for
	// a single channel image pixel value with range [0, 255]. Check pixels and recolor
	// as needed
	for (int i = 0; i < img.cols; i++) {
		for (int j = 0; j < img.rows; j++) {
			out.at<cv::Vec3b>(cv::Point(i, j)) = imgGray.at<uchar>(cv::Point(i, j));

			// some random small number here to check, not known prior to running
			// so this is some heuristic variable, should be found out somehow at runtime?
			if (harris.at<float>(cv::Point(i, j)) > 0.002) {
				out.at<cv::Vec3b>(cv::Point(i, j)) = cv::Vec3b(50, 50, 255);
			}
		}
	}

	cv::imshow("In", img);
	cv::imshow("Gray corners", out);

	cv::waitKey(0);
}