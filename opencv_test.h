#pragma once

void run_blur_filters();			// somw different kind of noise smoothing filters - Median or bilinear are best to keep edges
void run_conv_filters();			// cnn kernel using 2d conv filter
void run_sobel_filter();			// sobel operator
void run_laplacian();				// laplacian operator
void run_drawing_methods_I();		// some drawing methods for rectangles, lines, circles and ellipses
void run_drawing_methods_II();		// some more drawing methods for text, drawing and filling polylines
void run_image_contour_drawing();	// takes an input of a vector of points and draws the contours of each vector 
									// i.e draw polyline for each vector
void run_resize();					// rescale or resize an image to either a new given size, or proportionally along axes
void run_warp_perspective();		// transform source image using a transformation matrix that is applied to each pixel
void run_affine_transform();		// transform source image usign a transformation matrix that is applied to each pixel
									// difference with warpPerspective is that the image is not crushed