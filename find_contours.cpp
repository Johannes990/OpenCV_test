#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_find_contours() {
	// findContours takes a single channel binary (non-zero pixel treated as 1) image as an input
	cv::Mat input = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat binaryImg;
	cv::Mat contoursImg = cv::Mat::zeros(input.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Point offset;
	const int mode = cv::RETR_TREE;		// RETR_EXTERNAL - retrieves all the extreme outer contours for all contours
										// RETR_LIST - retrieves all contours without hierarchy
										// RETR_CCOMP - retrieves all contours and organizes them into a two-level hierarchy
										// RETR_TREE - retrieves all contours and reconstructs a full hierarchy of nested contours
										// RETR_FLOODFILL - ???
	const int method = cv::CHAIN_APPROX_SIMPLE; // CHAIN_APPROX_NONE - stores absolutely all contour points
												// CHAIN_APPROX_SIMPLE - compresses straight lines to just endpoints
												// CHAIN_APPROX_TC89_L1 - one flavor of the Teh-Chin chain approx. algorithm
												// CHAIN_APPROX_TC89_KCOS - one flavor of the Teh_Chin chain approx. algorithm

	cv::threshold(input, binaryImg, 100, 255, cv::THRESH_BINARY);

	cv::findContours(binaryImg, contours, hierarchy, mode, method);

	// print contour info to stdout
	std::cout << "Found " << contours.size() << " contours." << std::endl;
	for (cv::Vec4i k : hierarchy)
		std::cout << k << std::endl;

	// number all the contours
	for (int i = 0; i < contours.size(); i++) {
		cv::putText(contoursImg, std::to_string(i), contours[i][0], 1, 1, cv::Scalar(255, 255, 255), 1);
	}

	// -1 given as the contourIdx variable will draw all of the contours
	cv::drawContours(contoursImg, contours, -1, cv::Scalar(0, 255, 255), 1);
	
	cv::namedWindow("Input", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Binary", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Contours", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Input", input);
	cv::imshow("Binary", binaryImg);
	cv::imshow("Contours", contoursImg);
	
	cv::waitKey(0);
}