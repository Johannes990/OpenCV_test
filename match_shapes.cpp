#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_match_shapes() {
	cv::Mat letters = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\letters.png", cv::IMREAD_GRAYSCALE);
	cv::Mat rLetter = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\r_letter.png", cv::IMREAD_GRAYSCALE);
	cv::Mat wLetter = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\w_letter.png", cv::IMREAD_GRAYSCALE);
	cv::Mat out = cv::Mat::zeros(letters.size(), CV_8UC3);
	std::vector<std::vector<cv::Point>> lettersContours;
	std::vector<std::vector<cv::Point>> rContours;
	std::vector<std::vector<cv::Point>> wContours;
	std::vector<cv::Vec4i> lettersHierarchy;
	std::vector<cv::Vec4i> rHierarchy;
	std::vector<cv::Vec4i> wHierarchy;
	cv::Scalar contourColor = cv::Scalar(45, 50, 255);

	cv::threshold(letters, letters, 100, 255, cv::THRESH_BINARY);
	cv::threshold(rLetter, rLetter, 100, 255, cv::THRESH_BINARY);
	cv::threshold(wLetter, wLetter, 100, 255, cv::THRESH_BINARY);
	cv::findContours(letters, lettersContours, lettersHierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);
	cv::drawContours(out, lettersContours, -1, contourColor, 1);

	cv::imshow("In", letters);
	cv::imshow("Out", out);

	cv::waitKey(0);
}