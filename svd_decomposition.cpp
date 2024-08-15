#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_svd_decomposition() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatImg, U, W, Vt;

	// SVDecomp takes float input
	img.convertTo(floatImg, CV_32F);
	cv::SVDecomp(floatImg, W, U, Vt);

	cv::Mat WCompressed = cv::Mat::zeros(W.size(), W.type());

	// W size was 1x400, so 400 is the max length of the array
	// i.e. we get all the information from W if we go to 400
	// if we go less than 400, we get less info -> compression
	// const int threshold = 400; // 25.4 kB
	// const int threshold = 300; // 25.4 kB
	// const int threshold = 200; // 29.5 kB
	const int threshold = 100; // 42.5 kB <- image size increases due to added noise

	// for initial values of W, we get more detail in the image
	// the higher the threshold is set, the more detail we are incorporating into
	// WCompressed
	for (int i = 0; i < threshold; i++) {
		WCompressed.at<float>(cv::Point(0, i)) = W.at<float>(cv::Point(0, i));
	}

	// W is a stored as a single row but mathematically should be a diagonal matrix
	// let's convert
	cv::Mat diagW = cv::Mat::diag(WCompressed);
	cv::Mat res = U * diagW * Vt; // input = U * W * Vt by definition

	cv::convertScaleAbs(res, res); // convert back to unsigned char

	std::string filename = "random" + std::to_string(threshold) + ".jpg";
	cv::imwrite("C:\\Users\\johan\\OneDrive\\Pictures\\" + filename, res);

	cv::namedWindow("In", cv::WINDOW_NORMAL);

	cv::imshow("In", res);

	cv::waitKey(0);
}