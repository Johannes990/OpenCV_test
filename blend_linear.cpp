#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_blend_linear() {
	// same size and type images must be used
	cv::Mat inputImg1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat inputImg2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\top.jpg");
	cv::Mat outputImg;
	cv::Mat weights1 = cv::Mat::ones(inputImg1.size(), CV_32FC1);
	cv::Mat weights2(inputImg1.size(), CV_32FC1, cv::Scalar(4));
	cv::namedWindow("image blending output", cv::WINDOW_GUI_NORMAL);

	cv::Mat input3(inputImg1.size(), CV_8UC3, cv::Scalar(0, 0, 0));
	cv::putText(input3, "Some random text here", cv::Point(25, 50), 1, 4.5, cv::Scalar(0, 255, 255), 3);

	cv::Mat weightMat1(inputImg1.size(), CV_32FC1, cv::Scalar(3));
	cv::Mat weightMat2(inputImg1.size(), CV_32FC1, cv::Scalar(7));


	for (int i = 0; i < inputImg1.cols; i++) {
		for (int j = 0; j < inputImg1.rows; j++) {
			if ((int)input3.at<cv::Vec3b>(cv::Point(i, j))[2] < 254 && (int)input3.at<cv::Vec3b>(cv::Point(i, j))[1] < 254) {
				weightMat2.at<float>(cv::Point(i, j)) = 0;
			}
		}
	}
	
	//cv::blendLinear(inputImg1, inputImg2, weights1, weights2, outputImg);
	cv::blendLinear(inputImg1, input3, weightMat1, weightMat2, outputImg);

	cv::imshow("image blending output", outputImg);

	cv::waitKey(0);
}