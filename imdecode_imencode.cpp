#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imdecode_imencode() {
	cv::Mat image = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\4colors.png", cv::IMREAD_COLOR);
	std::vector<uchar> buffer;

	cv::namedWindow("img -> membuffer -> img", cv::WINDOW_NORMAL);

	cv::imencode(".png", image, buffer);

	// how large is the buffer for a 60x60 pixel image?
	std::cout << "Buffer size: " << buffer.size() << std::endl;	// apparently 617 uchars

	cv::Mat decodedImage = cv::imdecode(buffer, cv::IMREAD_COLOR);

	cv::imshow("img -> membuffer -> img", decodedImage);

	cv::waitKey(0);
}