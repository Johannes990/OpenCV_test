#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_data_types() {
	// unsigned char
	cv::Mat _8uc1 = cv::Mat::zeros(cv::Size(5, 5), CV_8UC1);
	std::cout << "_8uc1 matrix: " << _8uc1 << std::endl;
	std::cout << "_8uc1 matrix depth: " << _8uc1.depth() << std::endl;
	std::cout << "_8uc1 matrix type: " << _8uc1.type() << std::endl;	// type depends on the data type
																		// for example, CV_8UC1 has type 0, CV_8UC2 has type of 8 and so on
	std::cout << "_8uc1 matrix size: " << _8uc1.size() << std::endl;
	std::cout << "_8uc1 matrix cols: " << _8uc1.cols << std::endl;
	std::cout << "_8uc1 matrix rows: " << _8uc1.rows << std::endl;
	std::cout << "_8uc1 matrix channels: " << _8uc1.channels() << std::endl;	// channels are the last number of the data type, for example:
																				// CV_8UC1 - 1 channel
																				// CV_8UC2 - 2 channels
																				// CV_8UC3 - 3 channels
																				// ...
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);	// cv::IMREAD_GRAYSCALE read in single
																											// so the image type is CV_8UC1 or 0
																											// default is CV_8UC3 or 8 bits & 3 channels
	std::cout << "img depth: " << img.depth() << std::endl;
	std::cout << "img type: " << img.type() << std::endl;

	// signed char
	cv::Mat _8sc1 = cv::Mat::zeros(cv::Size(5, 5), CV_8SC1);

	// change a value at a particular pixel position
	_8sc1.at<char>(cv::Point(2, 3)) = 100;
	_8sc1.at<char>(cv::Point(1, 3)) = -120;
	std::cout << _8sc1 << std::endl;
	std::cout << "_8sc1 matrix: " << _8sc1 << std::endl;
	std::cout << "_8sc1 matrix depth: " << _8sc1.depth() << std::endl;
	std::cout << "_8sc1 matrix type: " << _8sc1.type() << std::endl;
	std::cout << "_8sc1 matrix channels: " << _8sc1.channels() << std::endl;

	cv::namedWindow("8UC1", 0);
	cv::imshow("8UC1", _8uc1);
	cv::namedWindow("8SC1", 0);
	cv::imshow("8SC1", _8sc1);
	cv::waitKey(0);
}