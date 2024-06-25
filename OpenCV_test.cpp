// OpenCV_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2\opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("C:\\Users\\johan\\OneDrive\\Pictures\\pildid\\IMG_20240624_182926.jpg", cv::IMREAD_COLOR);
    cv::Mat bilateralImg, gaussianBlurImg, medianBlurImg, cannyImg, grayScaleImg, dilateImg, erodeImg, laplacianImg, sobelImg;
    cv::namedWindow("Sobel Output", cv::WINDOW_NORMAL);

    double sigmaValue = 150.0;

    //cv::bilateralFilter(img, bilateralImg, 7, sigmaValue, sigmaValue);
    //cv::GaussianBlur(img, gaussianBlurImg, cv::Size(11, 11), 10);
    //cv::medianBlur(img, medianBlurImg, 11);

    // grayscale the image
    //cv::cvtColor(bilateralImg, grayScaleImg, cv::COLOR_BGR2GRAY);

    // edge detection
    //cv::Canny(grayScaleImg, cannyImg, 50.0, 200.0);

    // using dilate and erode on the source image
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ERODE, cv::Size(15, 15));
    //cv::dilate(img, dilateImg, kernel);
    //cv::erode(img, erodeImg, kernel);

    // Laplacian of an image (?)
    //cv::Laplacian(img, laplacianImg, 3, 5, 1.0, 1.0);

    int dx = 1;
    int dy = 0;
    int sobelKernelSize = 3;
    double scaleFactor = 1.0;
    double delta = 1.0;

    while (true) {
        // Sobel operator result on our image
        cv::cvtColor(img, grayScaleImg, cv::COLOR_BGR2GRAY);
        cv::Sobel(grayScaleImg, sobelImg, CV_8UC1, dx, dy, sobelKernelSize, scaleFactor, delta);

        //cv::imshow("Regular image", img);
        //cv::imshow("Regular image with bilateral filtering", bilateralImg);
        //cv::imshow("Canny image", cannyImg);
        //cv::imshow("Regular image with dilate", dilateImg);
        //cv::imshow("Regular image with erosion", erodeImg);
        //cv::imshow("Laplacian of regular image", laplacianImg);
        cv::imshow("Sobel Output", sobelImg);
        //cv::imshow("Regular image with Gaussian blur", gaussianBlurImg);
        //cv::imshow("Regular image with median blur", medianBlurImg);

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
