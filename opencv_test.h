#pragma once

void run_blur_filters();			// some different kind of noise smoothing filters - Median or bilinear are best to keep edges
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
void run_rotation();				// rotations
void data_types();					// some differences between OpenCV built-in data types
void run_convert_maps();			// convertMaps is a function that converts Matrices between data types. Example of use
void run_remap();					// remap applies a generic geometrical transformation to an image.
									// This actually means that we are mapping pixels from the original image into 2 maps:
									// one for the x (idx m) axis and one for the y (idx n) axis. the final image is 
									// then read sequentially from the x (at idx i) and y (at idx j) maps and the 
									// value there inserted to the final image at position i, j. original (m, n) -> final (i, j)
void run_polar_transformations();	// functions to transform an image between linear and polar coordinates
void run_rectangle_sub_pixel();		// getRectSubPix gets a pixel rectangle from an image with sub-pixel accuracy
									// meaning values between original pixels are filled with interpolated values
void run_threshold();				// only pixels above threshold value are included in the output image (other types available)
void run_adaptive_threshold();		// like threshold but takes into account kernels of pixels
void run_integral();				// calculates the integral of an image from top left pixel to the given pixel. value is
									// sum of the counted pixel values
void run_distance_transform();		// calculates the distance to the closest zero pixel for each pixel of the source image
void run_blend_linear();			// linear blending of two images
void run_grab_cut();				// image segmentation using the grab cut algorithm
void run_watershed();				// image segmentation using the watershed algorithm
void run_flood_fill();				// fills connected components of an image with given colors
void run_cvt_color();				// converts an image from one color space into another
void run_cvt_color_two_plane();		// cvtColorTwoPlane converts an image from one color space to another space where the
									// source image is stored in two planes.
void run_demosaicing();				// demosaicing() is the main function for all demosaicing processes
void run_apply_color_map();			// apply a color map to some image
void run_equalize_histogram();		// equalizes the histogram of pixel intensities of the image - increases the dynamic range
void run_calculate_histogram();		// calculate and draw the histogram curve for our image
