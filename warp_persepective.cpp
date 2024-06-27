#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_warp_perspective() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg");
	cv::Mat warped;
	std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja_warped.jpg";

	cv::namedWindow("initial", 0);
	cv::namedWindow("warped", 0);

	// Points to choose from image for getting perspective matrix
	cv::Point2f srcPoints[] = {
		cv::Point(685, 776),
		cv::Point(637, 1262),
		cv::Point(3250, 750),
		cv::Point(3291, 1257)
	};

	// Points for the destination perspective
	cv::Point2f dstPoints[] = {
		cv::Point(0, 0),
		cv::Point(0, 486),
		cv::Point(2610, 0),
		cv::Point(2610, 486)
	};

	// get the perspective transform matrix
	cv::Mat matrix = cv::getPerspectiveTransform(srcPoints, dstPoints);

	std::cout << matrix << std::endl;

	// do the actual warping
	cv::warpPerspective(img, warped, matrix, cv::Size(3200, 695));

	cv::imshow("initial", img);
	cv::imshow("warped", warped);

	cv::imwrite(filename, warped);
	cv::waitKey(0);
}