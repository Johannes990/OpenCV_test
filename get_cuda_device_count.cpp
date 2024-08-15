#include <opencv2/opencv.hpp>
#include "opencv_test.h"


void run_get_cuda_device_count() {
	int CUDADeviceCount = cv::cuda::getCudaEnabledDeviceCount();

	// getCudaEnabledDeviceCount() returns 0 if OpenCV is installed without CUDA support
	// ........................... returns -1 if CUDA driver is not installed or is incompatible
	// ........................... returns no of CUDA devices otherwise

	if (CUDADeviceCount == 0) {
		std::cout << "OpenCV installed without CUDA support" << std::endl;
	}
	else if (CUDADeviceCount == -1) {
		std::cout << "No compatible CUDA driver found" << std::endl;
	}
	else {
		std::cout << "Found " << CUDADeviceCount << " compatible CUDA devices" << std::endl;
	}
}