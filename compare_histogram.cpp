#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_compare_histogram() {
	cv::Mat src1, src2, src3, histOut1, histOut2, histOut3, graph1, graph2, graph3;
	src1 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_GRAYSCALE);
	src2 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan2.jpg", cv::IMREAD_GRAYSCALE);
	src3 = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan3.jpg", cv::IMREAD_GRAYSCALE);

	float range[] = { 0, 256 };
	const float* histRange = { range };
	const int histSize = 256;
	const int channelNum = 0;
	const int height = src1.size().height; // all pics same size
	const int width = src1.size().width;
	const int step = width / histSize;
	int ref1, ref2, ref3, idx1, idx2, idx3;
	int max1 = 0, max2 = 0, max3 = 0, sum1 = 0, sum2 = 0, sum3 = 0;

	cv::namedWindow("Hist 1", 0);
	cv::namedWindow("Hist 2", 0);
	cv::namedWindow("Hist 3", 0);

	cv::calcHist(&src1, 1, &channelNum, cv::Mat(), histOut1, 1, &histSize, &histRange);
	cv::calcHist(&src2, 1, &channelNum, cv::Mat(), histOut2, 1, &histSize, &histRange);
	cv::calcHist(&src3, 1, &channelNum, cv::Mat(), histOut3, 1, &histSize, &histRange);

	// results of compareHist function
	std::cout << "Compare histgoram 1 with histogram 2: " << std::to_string(cv::compareHist(histOut1, histOut2, cv::HISTCMP_CORREL)) << std::endl;
	std::cout << "Compare histgoram 1 with histogram 3: " << std::to_string(cv::compareHist(histOut1, histOut3, cv::HISTCMP_CORREL)) << std::endl;
	std::cout << "Compare histgoram 2 with histogram 3: " << std::to_string(cv::compareHist(histOut2, histOut3, cv::HISTCMP_CORREL)) << std::endl;

	for (int i = 0; i < histSize; i++) {
		sum1 += (int)histOut1.at<float>(cv::Point(0, i));
		sum2 += (int)histOut2.at<float>(cv::Point(0, i));
		sum3 += (int)histOut3.at<float>(cv::Point(0, i));
	}

	for (int i = 0; i < histSize; i++) {
		if ((int)histOut1.at<float>(cv::Point(0, i)) > max1) {
			max1 = (int)histOut1.at<float>(cv::Point(0, i));
			idx1 = i;
		}
		if ((int)histOut2.at<float>(cv::Point(0, i)) > max2) {
			max2 = (int)histOut2.at<float>(cv::Point(0, i));
			idx2 = i;
		}
		if ((int)histOut3.at<float>(cv::Point(0, i)) > max3) {
			max3 = (int)histOut3.at<float>(cv::Point(0, i));
			idx3 = i;
		}
	}

	double ratio1 = max1 / height;
	double ratio2 = max2 / height;
	double ratio3 = max3 / height;

	graph1 = cv::Mat::zeros(src1.size(), CV_8UC1);
	graph2 = cv::Mat::zeros(src2.size(), CV_8UC1);
	graph3 = cv::Mat::zeros(src3.size(), CV_8UC1);

	for (int i = 0; i < histSize; i++) {
		if (i != 0) {
			cv::line(graph1, cv::Point((i - 1) * step, (height - 1) - (ref1 / ratio1)), cv::Point(i * step, (height - 1) - (int)histOut1.at<float>(cv::Point(0, i)) / ratio1), cv::Scalar(255), 1);
			cv::line(graph2, cv::Point((i - 1) * step, (height - 1) - (ref2 / ratio2)), cv::Point(i * step, (height - 1) - (int)histOut2.at<float>(cv::Point(0, i)) / ratio2), cv::Scalar(255), 1);
			cv::line(graph3, cv::Point((i - 1) * step, (height - 1) - (ref3 / ratio3)), cv::Point(i * step, (height - 1) - (int)histOut3.at<float>(cv::Point(0, i)) / ratio3), cv::Scalar(255), 1);
		}
		ref1 = (double)histOut1.at<float>(cv::Point(0, i));
		ref2 = (double)histOut2.at<float>(cv::Point(0, i));
		ref3 = (double)histOut3.at<float>(cv::Point(0, i));
	}

	cv::imshow("Hist 1", graph1);
	cv::imshow("Hist 2", graph2);
	cv::imshow("Hist 3", graph3);

	cv::waitKey(0);
}