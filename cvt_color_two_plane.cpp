#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_cvt_color_two_plane() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat yuv, out;
	cv::Rect r(0, 0, img.cols, img.rows);

	cv::namedWindow("Original image", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("YUV Y channel", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("YUV V channel", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("YUV U channel", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("YUV converted back to BGR", cv::WINDOW_GUI_NORMAL);
	
	// step 1 - BGR to YUV
	cv::cvtColor(img, yuv, cv::COLOR_BGR2YUV_I420);

	// step 2 - split YUV to Y-U-V
	cv::Mat vChannel = cv::Mat::zeros(cv::Size(img.cols / 2, img.rows / 2), CV_8UC1);
	cv::Mat uChannel = cv::Mat::zeros(cv::Size(img.cols / 2, img.rows / 2), CV_8UC1);

	for (int i = img.rows; i < img.rows + (img.rows / 4); i++) {
		for (int j = 0; j < yuv.cols; j++) {
			if (j < yuv.cols / 2) {
				vChannel.at<uchar>(cv::Point(j, (i - img.rows) * 2)) = yuv.at<uchar>(cv::Point(j, i));
			}
			else {
				vChannel.at<uchar>(cv::Point(j - yuv.cols / 2, (i - img.rows) * 2 + 1)) = yuv.at<uchar>(cv::Point(j, i));
			}
		}
	}

	for (int i = img.rows + (img.rows / 4); i < yuv.rows; i++) {
		for (int j = 0; j < yuv.cols; j++) {
			if (j < yuv.cols / 2) {
				uChannel.at<uchar>(cv::Point(j, (i - img.rows - img.rows / 4) * 2)) = yuv.at<uchar>(cv::Point(j, i));
			}
			else {
				uChannel.at<uchar>(cv::Point(j - yuv.cols / 2, (i - img.rows - img.rows / 4) * 2 + 1)) = yuv.at<uchar>(cv::Point(j, i));
			}
		}
	}

	cv::Mat yChannel = yuv(r);

	// step 3 - cvtColorTwoPlane
	cv::Mat uvChannel;
	std::vector<cv::Mat> uvVector;
	uvVector.push_back(vChannel);
	uvVector.push_back(uChannel);
	cv::merge(uvVector, uvChannel);

	cv::cvtColorTwoPlane(yChannel, uvChannel, out, cv::COLOR_YUV2BGRA_NV12);

	cv::imshow("Original image", img);
	cv::imshow("YUV Y channel", yChannel);
	cv::imshow("YUV U channel", uChannel);
	cv::imshow("YUV V channel", vChannel);
	cv::imshow("YUV converted back to BGR", out);

	cv::waitKey(0);
}