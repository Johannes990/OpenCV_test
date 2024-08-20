#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_imdecode_imencode() {
	cv::Mat image = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\rims.jpeg", cv::IMREAD_COLOR);
	std::vector<uchar> buffer;

	cv::imencode(".jpg", image, buffer);

	// how large is the buffer for a 60x60 pixel image?
	std::cout << "Buffer size: " << buffer.size() << std::endl;	// apparently 617 uchars

	cv::Mat decodedImage = cv::imdecode(buffer, cv::IMREAD_COLOR);

	// let's check how much is the difference between original and decoded image
	cv::Mat difference;
	cv::compare(image, decodedImage, difference, cv::CmpTypes::CMP_EQ);

	cv::imshow("original image", image);
	cv::imshow("decoded image", decodedImage);
	cv::imshow("difference between original and decoded image", difference);

	cv::waitKey(0);
}