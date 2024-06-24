// OpenCV_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2\opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\IMG_20240624_182926.jpg", cv::IMREAD_COLOR);
    cv::Mat bilateralImg, gaussianBlurImg, medianBlurImg;

    double sigmaValue = 50.0;

    cv::bilateralFilter(img, bilateralImg, 15, sigmaValue, sigmaValue);
    cv::GaussianBlur(img, gaussianBlurImg, cv::Size(11, 11), 10);
    cv::medianBlur(img, medianBlurImg, 11);

    cv::imshow("Regular image", img);
    cv::imshow("Regular image with bilateral filtering", bilateralImg);
    cv::imshow("Regular image with Gaussian blur", gaussianBlurImg);
    cv::imshow("Regular image with median blur", medianBlurImg);

    cv::waitKey(0);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
