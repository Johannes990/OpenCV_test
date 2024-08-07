#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dct() {
	// discrete cosine transform needs a single channel float image
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatImg, dctImg, idctImg, output;

	img.convertTo(floatImg, CV_32F);

	cv::dct(floatImg, dctImg); // cosine transform converts from space domain to freq domain
	// show the output of the frequency domain of the image visually
	//cv::convertScaleAbs(dctImg, output);

	/*
	* The output of dct() has in essence coefficients of the initial image pixels
	* If the coefficient is close to 0, that means it is a more detailed part of the image
	* Let's try to remove some of the small details to compress the image
	* Here we use std::abs() since float values can also be negative
	* 
	* threshold = 1 will give a picture that takes 2.28 MB of space
	* threshold = 20 will give a picture that takes 2.38 MB of space
	* threshold = 200 will give a picture that takes 1.16 MB of space
	* threshold = 600 will give a picture that takes 746 KB of space
	*/
	const int threshold = 600;
	for (int i = 0; i < dctImg.rows; i++) {
		for (int j = 0; j < dctImg.cols; j++) {
			if (std::abs(dctImg.at<float>(i, j)) < threshold) {
				dctImg.at<float>(i, j) = 0; // just set the value to zero, thereby losing detail
			}
		}
	}

	cv::idct(dctImg, idctImg); // convert back from freq domain to space domain
	cv::convertScaleAbs(idctImg, output);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", output);
	cv::imwrite("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja_compressed.jpg", output);

	cv::waitKey(0);
}
