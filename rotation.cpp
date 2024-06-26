#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_rotation() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg");
	cv::Mat rotatedImg = cv::Mat::zeros(cv::Size(inputImg.cols, inputImg.rows), inputImg.type());
	int angle = 1;
	double scale = 1.0;
	cv::Point2f center(inputImg.cols / 2.0, inputImg.rows / 2.0);

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Rotated image", cv::WINDOW_GUI_NORMAL);

	cv::imshow("Original image", inputImg);

	int frameCount = 0;
	double fps = 0.0;
	auto startTime = std::chrono::high_resolution_clock::now();

	while (angle++) {
		cv::Mat rotMatrix = cv::getRotationMatrix2D(center, (double)angle, scale);

		cv::warpAffine(inputImg, rotatedImg, rotMatrix, inputImg.size());

		// do some fps counting
		frameCount++;
		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = currentTime - startTime;
		if (elapsed.count() >= 1.0) {
			fps = frameCount / elapsed.count();
			frameCount = 0;
			startTime = currentTime;
		}

		cv::putText(rotatedImg, "FPS: " + std::to_string(fps), cv::Point(10, 130), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(255, 0, 0), 2, cv::LINE_AA);

		cv::imshow("Rotated image", rotatedImg);
		std::cout << "before wait" << std::endl;
		cv::waitKey(1);
		std::cout << "after wait" << std::endl;
	}
}