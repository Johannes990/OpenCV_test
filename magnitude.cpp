#include <opencv2/opencv.hpp>
#include "opencv_test.h"


std::string printVector(std::vector<float>& vec) {
	std::string returnString;

	for (int i = 0; i < vec.size(); i++) {
		returnString.append(std::to_string(vec[i]));
		if (i < vec.size() - 1) {
			returnString.append(", ");
		}
	}

	return returnString;
}

void run_magnitude() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat randImg = cv::Mat::zeros(img.size(), img.type());
	cv::Mat imgFloat, randImgFloat;
	cv::Mat magnitude = cv::Mat::zeros(img.size(), CV_32F);

	std::vector<float> x;
	std::vector<float> y;
	cv::Mat magXY;

	x.push_back(1);
	x.push_back(3);
	x.push_back(3);
	x.push_back(6);

	y.push_back(1);
	y.push_back(4);
	y.push_back(2);
	y.push_back(8);

	cv::magnitude(x, y, magXY);

	std::cout << "Vector x: " << printVector(x) << std::endl;
	std::cout << "Vector y: " << printVector(y) << std::endl;
	std::cout << "result of cv::magnitude(x, y, magXY) -> magXY: " << magXY << std::endl;

	cv::namedWindow("In1", cv::WINDOW_NORMAL);
	cv::namedWindow("In2", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	img.convertTo(imgFloat, CV_32F);
	cv::randn(randImg, 10, 5);
	randImg.convertTo(randImgFloat, CV_32F);
	cv::magnitude(imgFloat, randImgFloat, magnitude);


	cv::imshow("In1", img);
	cv::imshow("In2", randImg);
	cv::imshow("Out", magnitude);

	cv::waitKey(0);
}