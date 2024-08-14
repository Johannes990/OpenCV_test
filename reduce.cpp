#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_reduce() {
	//const std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\10_08_2024\\IMG_20240806_142444.jpg";
	//cv::Mat img = cv::imread(filename, cv::IMREAD_COLOR);
	cv::Mat small = (cv::Mat_<float>(3, 3) << 0.5, 0.5, 1.5, 3.3, 2.6, 18.0, -3.4, 7.4, 1.1);
	cv::Mat smallReduceResult;

	cv::reduce(small, smallReduceResult, 1, cv::REDUCE_AVG);

	std::cout << "Matrix\n" << small << std::endl;
	std::cout << "is reduced to a single row with cv::REDUCE_MAX with result\n" << smallReduceResult << std::endl;
}
