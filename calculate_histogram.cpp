#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_calculate_histogram() {
	cv::Mat src, dst, histOut;
	src = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\paneelmaja.jpg", cv::IMREAD_COLOR);

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("Out", cv::WINDOW_GUI_NORMAL);

	// run the calcHist function
	float range[] = { 0, 256 };
	const float* histRange = { range };
	const int histSize = 256;
	const int channelNum = 2;

	cv::calcHist(&src, 1, &channelNum, cv::Mat(), histOut, 1, &histSize, &histRange);

	// summing
	int sum = 0;

	for (int k = 0; k < histSize; k++) {
		sum += (int)histOut.at<float>(cv::Point(0, k));
		std::cout << (int)histOut.at<float>(cv::Point(0, k)) << " ";
	}

	std::cout << std::endl;
	std::cout << "Histogram sum: " << sum << std::endl;

	// drawing histogram
	int max = 0, index, ref;
	const int height = src.size().height;
	const int width = src.size().width;
	const int step = width / histSize;

	std::cout << "Height: " << height << ", width: " << width << std::endl;

	for (int k = 0; k < histSize; k++) {
		if ((int)histOut.at<float>(cv::Point(0, k)) > max) {
			max = (int)histOut.at<float>(cv::Point(0, k));
			index = k;
		}
	}

	double ratio = max / height;

	std::cout << max << " " << index * 2 << " " << ratio << std::endl;

	cv::Mat graph = cv::Mat::zeros(src.size(), CV_8UC1);
	
	for (int i = 0; i < histSize; i++) {
		if (i != 0) {
			cv::line(graph, cv::Point((i - 1) * step, (height - 1) - (ref / ratio)), cv::Point(i * step, (height - 1) - (int)histOut.at<float>(cv::Point(0, i)) / ratio), cv::Scalar(255), 1);
		}
		ref = (double)histOut.at<float>(cv::Point(0, i));
	}

	cv::imshow("In", src);
	cv::imshow("Out", graph);

	cv::waitKey(0);
}