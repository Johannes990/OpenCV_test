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

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	cv::threshold(letters, letters, 100, 255, cv::THRESH_BINARY);
	cv::threshold(rLetter, rLetter, 100, 255, cv::THRESH_BINARY);
	cv::threshold(wLetter, wLetter, 100, 255, cv::THRESH_BINARY);
	cv::findContours(letters, lettersContours, lettersHierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::findContours(rLetter, rContours, rHierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::findContours(wLetter, wContours, wHierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::drawContours(out, lettersContours, -1, contourColor, 1);
	std::vector<cv::Moments> M(lettersContours.size());
	std::vector<cv::Point> rContour = rContours[0];
	std::vector<cv::Point> wContour = wContours[0];

	for (int i = 0; i < lettersContours.size(); i++) {
		M[i] = cv::moments(lettersContours[i]);
		cv::Point massCenter(M[i].m10 / M[i].m00, M[i].m01 / M[i].m00);
		int compMethod = cv::CONTOURS_MATCH_I1;

		cv::putText(out, std::to_string(i), massCenter, 1, 1, cv::Scalar(130, 130, 130), 1);

		// compare 'R' letters
		double rCompResult = cv::matchShapes(lettersContours[i], rContour, compMethod, 0);
		std::cout << "Comparing the letter 'R' with contour " << i << " has result: " << rCompResult << std::endl;

		// compare 'W' letters
		double wCompResult = cv::matchShapes(lettersContours[i], wContour, compMethod, 0);
		std::cout << "Comparing the letter 'W' with contour " << i << " has result: " << wCompResult << std::endl;
	}

	cv::imshow("In", letters);
	cv::imshow("Out", out);

	cv::waitKey(0);
}