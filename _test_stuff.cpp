#include <opencv2\opencv.hpp>
#include "opencv_test.h"
#include <iostream>

using namespace cv;
using namespace std;

int N = 7;
int thresh = 100;

// get angle between vectors pt0->pt1 and pt0->pt2
static double calculateAngle(Point pt1, Point pt2, Point pt0) {
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;

	return (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
}

// get corners
void find_squares(const Mat& image, vector<vector<Point>>& squares) {
	squares.clear();

	Mat pyr, timg, gray0(image.size(), CV_8U), gray;

	// down-scale ant then up-scale to filter noise
	pyrDown(image, pyr, Size(image.cols / 2, image.rows / 2));
	pyrUp(pyr, timg, image.size());
	vector<vector<Point>> contours;

	// get squares from every color plane of the image
	for (int c = 0; c < 3; c++) {
		int ch[] = { c, 0 };
		mixChannels(&timg, 1, &gray0, 1, ch, 1);

		// try several threshold levels, here N = 11 for example
		for (int lvl = 0; lvl < N; lvl++) {
			// hack where we use Canny when lvl = 0
			// Canny helps to catch squares with gradient shading
			if (lvl == 0) {
				Canny(gray0, gray, 0, thresh, 5); // upper threshold from slider
				dilate(gray, gray, Mat(), Point(-1, -1)); // dilate to remove potential holes between edge segments
			}
			else {
				gray = gray0 >= (lvl + 1) * 255 / N; // apply threshold
			}

			findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

			vector<Point> approx;

			// test each contour
			for (int i = 0; i < contours.size(); i++) {
				// approx contour with acc proportional to contour perimeter (wut?)
				approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);

				// square contours should have 4 vertices after approx
				// relatively large area (to filter out noisy contours)
				// and be convex
				if (approx.size() == 4 && fabs(contourArea(approx)) > 1000 && isContourConvex(approx)) {
					double maxCos = 0;
					for (int j = 2; j < 5; j++) {
						double cosine = fabs(calculateAngle(approx[j % 4], approx[j - 2], approx[j - 1]));
						maxCos = MAX(cosine, maxCos);
					}

					// if cosine of all angles is small
					// then add vertices to result
					if (maxCos < 0.3) {
						squares.push_back(approx);
					}
				}
			}
		}
	}
}


void show_squares() {
	Mat img = imread("C:\\Users\\johan\\OneDrive\\Pictures\\pilt11.jpg", IMREAD_COLOR);
	namedWindow("Lines", WINDOW_GUI_NORMAL);

	vector<vector<Point>> squares;

	find_squares(img, squares);

	polylines(img, squares, true, Scalar(0, 255, 0), 2, LINE_AA);
	imshow("Lines", img);

	waitKey(0);
}