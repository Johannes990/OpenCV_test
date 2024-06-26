#include <opencv2\opencv.hpp>
#include "opencv_test.h"


void run_sobel_filter() {
    cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\IMG_20240624_182926.jpg", cv::IMREAD_COLOR);
    cv::Mat grayScaleImg, sobelImg;
    cv::namedWindow("Sobel Output", cv::WINDOW_NORMAL);

    cv::cvtColor(img, grayScaleImg, cv::COLOR_BGR2GRAY);

    int dx = 1;
    int dy = 0;
    int sobelKernelSize = 3;
    double scaleFactor = 1.0;
    double delta = 1.0;

    while (true) {
        // Sobel operator result on our image
        cv::Sobel(grayScaleImg, sobelImg, CV_8UC1, dx, dy, sobelKernelSize, scaleFactor, delta);

        cv::imshow("Sobel Output", sobelImg);

        int c = cv::waitKey(1);

        if ((char)c == 'q') {
            std::cout << "Pressed 'q'. Quitting..." << std::endl;
            break;
        }
        else if ((char)c == 'a') {
            std::cout << "Pressed 'a'." << std::endl;
            if (dx && dy) {
                std::cout << "Setting dx = 0." << std::endl;
                dx = 0;
            }
            else {
                std::cout << "Setting dx = 1." << std::endl;
                dx = 1;
            }
        }
        else if ((char)c == 's') {
            std::cout << "Pressed 's'." << std::endl;
            if (dx && dy) {
                std::cout << "Setting dy = 0." << std::endl;
                dy = 0;
            }
            else {
                std::cout << "Setting dy = 1." << std::endl;
                dy = 1;
            }
        }
        else if ((char)c == 'z') {
            std::cout << "Pressed 'z'. Increasing Sobel kernel size by 2." << std::endl;
            sobelKernelSize += 2;
        }
        else if ((char)c == 'x') {
            std::cout << "Pressed 'x'. Decreasing Sobel kernel size by 2." << std::endl;
            if (sobelKernelSize >= 3) {
                sobelKernelSize -= 2;
            }
        }
        else if ((char)c == 'w') {
            std::cout << "Pressed 'w'. Increasing scale factor by 0.1" << std::endl;
            scaleFactor += 0.1;
        }
        else if ((char)c == 'e') {
            std::cout << "Pressed 'e'. Decreasing scale factor by 0.1" << std::endl;
            if (scaleFactor > 0.1) {
                scaleFactor -= 0.1;
            }
        }
    }
}