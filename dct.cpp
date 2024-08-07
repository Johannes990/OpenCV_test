#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_dct() {
	// discrete cosine transform needs a single channel float image
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_GRAYSCALE);
	cv::Mat floatImg, dctImg, idctImg;

	img.convertTo(floatImg, CV_32F);

	cv::Mat output = cv::Mat::zeros(floatImg.size(), floatImg.type());

	cv::dct(floatImg, dctImg); // cosine transform converts from space domain to freq domain
	// show the output of the frequency domain of the image visually
	//cv::convertScaleAbs(dctImg, output);
	cv::idct(dctImg, idctImg); // convert back from freq domain to space domain
	cv::convertScaleAbs(idctImg, output);

	cv::namedWindow("In", cv::WINDOW_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_NORMAL);

	cv::imshow("In", img);
	cv::imshow("Out", output);

	cv::waitKey(0);
}
