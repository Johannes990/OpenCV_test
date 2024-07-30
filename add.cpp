#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_add() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat smallMat = cv::Mat::zeros(3, 3, CV_8UC1);
	cv::Mat smallAddOut, imgAddOut;
	cv::Scalar singleChannelAddend = cv::Scalar(50); // add 50 to a single channel
	int tripleChannelAddendScalar = 50;
	int biasValue = -50;

	cv::namedWindow("Img", cv::WINDOW_NORMAL);
	cv::namedWindow("added", cv::WINDOW_NORMAL);

	cv::createTrackbar("Add value", "added", &tripleChannelAddendScalar, 100);

	cv::imshow("Img", img);

	// stdout print for small matrix
	std::cout << smallMat << std::endl;

	cv::add(smallMat, singleChannelAddend, smallAddOut);

	std::cout << smallAddOut << std::endl;

	cv::waitKey(0);

	// show image for a large matrix
	while (true) {
		cv::Scalar tripleChannelAddend = cv::Scalar(
			tripleChannelAddendScalar + biasValue,
			tripleChannelAddendScalar + biasValue,
			tripleChannelAddendScalar + biasValue
		); // add some amount to all three channels

		cv::add(img, tripleChannelAddend, imgAddOut);

		cv::imshow("added", imgAddOut);

		int ch = cv::waitKey(5);

		if ((char)ch == 'q') { break; }
	}
}