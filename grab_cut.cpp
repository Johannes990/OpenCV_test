#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_grab_cut() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg");
	cv::Mat result = inputImg.clone();
	cv::Mat mask, bgdModel, fgdModel;
	cv::Rect boundingBox = cv::selectROI(inputImg); // select a bounding box from the image
	int grabCutIterations = 5;

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Grab cut image", cv::WINDOW_GUI_NORMAL);

	std::cout << "GC_BGD as int: " << (int)cv::GC_BGD << std::endl;
	std::cout << "GC_FGD as int: " << (int)cv::GC_FGD << std::endl;
	std::cout << "GC_PR_BGD as int: " << (int)cv::GC_PR_BGD << std::endl;
	std::cout << "GC_PR_FGD as int: " << (int)cv::GC_PR_FGD << std::endl;

	cv::grabCut(inputImg, mask, boundingBox, bgdModel, fgdModel, grabCutIterations, cv::GC_INIT_WITH_RECT);

	// this nested loop to show some results
	for (int i = 0; i < inputImg.cols; i++) {
		for (int j = 0; j < inputImg.rows; j++) {
			// obvious background pixel
			if ((int)mask.at<uchar>(cv::Point(i, j)) == 0) {
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
			} 
			// obvious foreground pixel
			else if ((int)mask.at<uchar>(cv::Point(i, j)) == 1) {
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 255;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
			}
			// possible background pixel
			else if ((int)mask.at<uchar>(cv::Point(i, j)) == 2) {
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 255;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 255;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
			}
			// possible foreground pixel
			else if ((int)mask.at<uchar>(cv::Point(i, j)) == 3) {
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 0;
				result.at<cv::Vec3b>(cv::Point(i, j))[0] = 255;
			}
		}
	}

	cv::imshow("Grab cut image", result);
	cv::imshow("Original image", inputImg);

	cv::waitKey(0);
}