#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_apply_color_map() {
	cv::Mat inputImg = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\trashcan.jpg", cv::IMREAD_COLOR);
	cv::Mat dst1, dst2, dst3, dst4, dst5, dst6, dst7, dst8, dst9, dst10,
		dst11, dst12, dst13, dst14, dst15, dst16, dst17, dst18, dst19, dst20, dst21, dst22;
	cv::Mat dst23 = cv::Mat::zeros(inputImg.size(), inputImg.type());
	cv::Mat dst24 = cv::Mat::zeros(inputImg.size(), inputImg.type());
	cv::Mat out1, out2, out3, out4, out5, out6, out7, out8, out9, out10, out11, out12, out13, out14, out15, out16, out17, out18;
	cv::Mat doubleRow1, doubleRow2, doubleRow3, final1, final2;

	cv::namedWindow("In", cv::WINDOW_GUI_NORMAL);
	cv::namedWindow("All 22 predefined color maps in OpenCV", cv::WINDOW_GUI_NORMAL);

	cv::applyColorMap(inputImg, dst1, cv::COLORMAP_AUTUMN);
	cv::applyColorMap(inputImg, dst2, cv::COLORMAP_BONE);
	cv::applyColorMap(inputImg, dst3, cv::COLORMAP_JET);
	cv::applyColorMap(inputImg, dst4, cv::COLORMAP_WINTER);
	cv::applyColorMap(inputImg, dst5, cv::COLORMAP_RAINBOW);
	cv::applyColorMap(inputImg, dst6, cv::COLORMAP_OCEAN);
	cv::applyColorMap(inputImg, dst7, cv::COLORMAP_SUMMER);
	cv::applyColorMap(inputImg, dst8, cv::COLORMAP_SPRING);
	cv::applyColorMap(inputImg, dst9, cv::COLORMAP_COOL);
	cv::applyColorMap(inputImg, dst10, cv::COLORMAP_HSV);
	cv::applyColorMap(inputImg, dst11, cv::COLORMAP_PINK);
	cv::applyColorMap(inputImg, dst12, cv::COLORMAP_HOT);
	cv::applyColorMap(inputImg, dst13, cv::COLORMAP_PARULA);
	cv::applyColorMap(inputImg, dst14, cv::COLORMAP_MAGMA);
	cv::applyColorMap(inputImg, dst15, cv::COLORMAP_INFERNO);
	cv::applyColorMap(inputImg, dst16, cv::COLORMAP_PLASMA);
	cv::applyColorMap(inputImg, dst17, cv::COLORMAP_VIRIDIS);
	cv::applyColorMap(inputImg, dst18, cv::COLORMAP_CIVIDIS);
	cv::applyColorMap(inputImg, dst19, cv::COLORMAP_TWILIGHT);
	cv::applyColorMap(inputImg, dst20, cv::COLORMAP_TWILIGHT_SHIFTED);
	cv::applyColorMap(inputImg, dst21, cv::COLORMAP_TURBO);
	cv::applyColorMap(inputImg, dst22, cv::COLORMAP_DEEPGREEN);

	cv::hconcat(dst1, dst2, out1);
	cv::hconcat(dst3, dst4, out2);
	cv::hconcat(out1, out2, out3); //
	cv::hconcat(dst5, dst6, out4);
	cv::hconcat(dst7, dst8, out5);
	cv::hconcat(out4, out5, out6); //
	cv::hconcat(dst9, dst10, out7);
	cv::hconcat(dst11, dst12, out8);
	cv::hconcat(out7, out8, out9); //
	cv::hconcat(dst13, dst14, out10);
	cv::hconcat(dst15, dst16, out11);
	cv::hconcat(out10 ,out11, out12); //
	cv::hconcat(dst17, dst18, out13);
	cv::hconcat(dst19, dst20, out14);
	cv::hconcat(out13, out14, out15); //
	cv::hconcat(dst21, dst22, out16);
	cv::hconcat(dst23, dst24, out17);
	cv::hconcat(out16, out17, out18); //

	cv::vconcat(out3, out6, doubleRow1);
	cv::vconcat(out9, out12, doubleRow2);
	cv::vconcat(out15, out18, doubleRow3);
	cv::vconcat(doubleRow1, doubleRow2, final1);
	cv::vconcat(final1, doubleRow3, final2);

	cv::imshow("In", inputImg);
	cv::imshow("All 22 predefined color maps in OpenCV", final2);

	cv::waitKey(0);
}