#include <opencv2\opencv.hpp>


void run_laplacian() {
	cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\IMG_20240624_182926.jpg", cv::IMREAD_COLOR);
	cv::Mat laplacianImg;
	cv::namedWindow("Laplacian", cv::WINDOW_NORMAL);

	cv::Laplacian(img, laplacianImg, -1, 5, 1.0);

	cv::imshow("Laplacian", laplacianImg);

	cv::waitKey(0);
}