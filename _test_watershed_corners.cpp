#include <opencv2/opencv.hpp>
#include "opencv_test.h"


cv::Mat markersMask, mouseAreaImg;
cv::Point previousPt(-1, -1);

static void onMouse(int event, int x, int y, int flags,	void*)
{
	if (x < 0 || x >= mouseAreaImg.cols || y < 0 || y >= mouseAreaImg.rows)
		return;

	if (event == cv::EVENT_LBUTTONUP || !(flags & cv::EVENT_FLAG_LBUTTON))
		previousPt = cv::Point(-1, -1);
	else if (event == cv::EVENT_LBUTTONDOWN)
		previousPt = cv::Point(x, y);
	else if (event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_LBUTTON))
	{
		cv::Point pt(x, y);

		if (previousPt.x < 0)
			previousPt = pt;

		line(markersMask, previousPt, pt, cv::Scalar::all(255), 5, 8, 0);
		line(mouseAreaImg, previousPt, pt, cv::Scalar::all(255), 5, 8, 0);
		previousPt = pt;
		imshow("image", mouseAreaImg);
	}
}

void run_watershed_corners() {
	std::string filename = "C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\10_08_2024\\IMG_20240806_142444.jpg";
	cv::Mat img0 = cv::imread(filename, cv::IMREAD_COLOR), imgGray;

	if (img0.empty())
	{
		std::cout << "Couldn't open image ";
	}
	
	img0.copyTo(mouseAreaImg);
	cvtColor(mouseAreaImg, markersMask, cv::COLOR_BGR2GRAY);
	cvtColor(markersMask, imgGray, cv::COLOR_GRAY2BGR);
	markersMask = cv::Scalar::all(0);

	cv::namedWindow("image", cv::WINDOW_NORMAL);
	cv::namedWindow("watershed transform", cv::WINDOW_NORMAL);

	cv::imshow("image", mouseAreaImg);

	cv::setMouseCallback("image", onMouse, 0);

	for (;;)
	{
		char c = (char) cv::waitKey(0);
		if (c == 27)
			break;

		if (c == 'r')
		{
			markersMask = cv::Scalar::all(0);
			img0.copyTo(mouseAreaImg);
			imshow("image", mouseAreaImg);
		}

		if (c == 'w' || c == ' ')
		{
			int i, j, compCount = 0;
			std::vector<std::vector<cv::Point> > contours;
			std::vector<cv::Vec4i> hierarchy;
			findContours(markersMask, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

			if (contours.empty())
				continue;

			cv::Mat markers(markersMask.size(), CV_32S);
			markers = cv::Scalar::all(0);
			int idx = 0;

			for (; idx >= 0; idx = hierarchy[idx][0], compCount++)
				drawContours(markers, contours, idx, cv::Scalar::all(compCount + 1), -1, 8, hierarchy, INT_MAX);

			if (compCount == 0)
				continue;

			std::vector<cv::Vec3b> colorTab;

			for (i = 0; i < compCount; i++)
			{
				int b = cv::theRNG().uniform(0, 255);
				int g = cv::theRNG().uniform(0, 255);
				int r = cv::theRNG().uniform(0, 255);
				colorTab.push_back(cv::Vec3b((uchar)b, (uchar)g, (uchar)r));
			}

			double t = (double) cv::getTickCount();

			cv::watershed(img0, markers);

			t = (double) cv::getTickCount() - t;

			printf("execution time = %gms\n", t * 1000. / cv::getTickFrequency());

			cv::Mat wshed(markers.size(), CV_8UC3);
			// paint the watershed image

			for (i = 0; i < markers.rows; i++)
				for (j = 0; j < markers.cols; j++)
				{
					int index = markers.at<int>(i, j);
					if (index == -1)
						wshed.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 255, 255);
					else if (index <= 0 || index > compCount)
						wshed.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 0);
					else
						wshed.at<cv::Vec3b>(i, j) = colorTab[index - 1];
				}

			wshed = wshed * 0.5 + imgGray * 0.5;
			cv::imshow("watershed transform", wshed);
		}
	}
}