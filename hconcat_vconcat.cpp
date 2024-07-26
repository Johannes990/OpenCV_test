#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_hconcat_vconcat() {
	cv::Mat img1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\R.jpg");
	cv::Mat img2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\random.jpg");
	cv::Mat hConcat, vConcat;
	std::vector<cv::Mat> images;

	cv::namedWindow("Vertical concat", cv::WINDOW_NORMAL);
	cv::namedWindow("Horizontal concat", cv::WINDOW_NORMAL);

	/*
	* this will not work because the number of rows between images and the depth of images
	* must be equal when calling hconcat()
	* 
	* cv::hconcat(img1, img2, hConcat);
	* 
	* 
	* this will not work because the number of columns between images and the image depth
	* must be equal when calling vconcat()
	* 
	* cv::vconcat(img1, img2, vConcat);
	*/

	// resize images so they can be concatenated
	cv::resize(img2, img2, cv::Size(img2.cols, img1.rows));

	images.push_back(img1);
	images.push_back(img2);
	
	cv::hconcat(images, hConcat);

	cv::resize(img1, img1, cv::Size(img2.cols, img1.rows));

	cv::vconcat(img1, img2, vConcat);

	cv::imshow("Vertical concat", vConcat);
	cv::imshow("Horizontal concat", hConcat);

	cv::waitKey(0);
}