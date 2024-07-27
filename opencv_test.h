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
void run_data_types();					// some differences between OpenCV built-in data types
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
void run_compare_histogram();		// compare different histograms by some distance functions (correlation, chi-square etc)
void run_calculate_back_project();	// calculates the back projection of an image - this is used for image segmentation somehow
void show_squares();				//// quick test to see if i can get corners from an image of a house
void run_emd();						// Earth mover's distance - measures distance between 2 probability distributions over a region
									// Also known as the Wasserstein metric in mathematics
void run_clahe();					// contrast limited adaptive histogram equalization
void run_find_contours();			// algorithm to retrieve contours from a binary image, very useful for shape analysis,
									// object detection and recognition
void run_bounding_rect();			// get the bounding rectangle of some feature (contour)
void run_min_area_rect();			// get the minimum aera rectangle for a set of points or contour (this rectangle can be rotated)
void run_min_enclosing_circle();	// get the minimum area circle that encloses a contour
void run_min_enclosing_triangle();	// get the minimum area triangle around a contour
void run_contour_convex();			// return wether some contour is convex or concave
void run_arc_length();				// calculate a contour perimeter or arc length
void run_approx_poly_dp();			// Approximate a polygonal curve with specified precision
void run_convex_hull ();			// creates a set of points (convex hull) that surround a given set oh points
void run_fit_line();				// line fitting to a given point set (linear regression)
void run_rotated_rect_intersect();	// find if there is any intersection between 2 rotated rectangles
void run_connected_components();	// computes the connected components labeled image of bool image
void run_intersect_convex_convex();	// finds intersection of two convex polygons, returns area of intersection
									// if intersection exists
void run_contour_area();			// calculate the area of some contour
void run_point_polygon_test();		// pointPolygonTest checks wether a point is inside a polygon (positive),
									// lies on the edge (zero) or is outside it (negative)
void run_moments();					// calculates all moments up to the third order of a polygon / rasterized shape
void run_hu_moments();				// huMoments() function calculates 7 Hu invariants
void run_match_shapes();			// matchShapes() compares two contours and returns a value between 0 (similar) 
									// and 1 (dissimilar)
void run_canny();					// the canny edge detection algorithm
void run_corner_harris();			// corner detection using Harris algorithm
void run_corner_eigen_val_vect();	// eigen values and vectors for robust corner and edge detection
void run_green_detection_mask();	//// testing one possible way of removing trees and grass during corner detection
									//// - mask out green areas on the picture by hue
void run_good_features_to_track();	// optimized version of cornerHarris and cornerMinEigenVal
void run_hough_circles();			// finds circles in an image using a modification of the Hough transform
void run_hough_lines();				// line detection from a binary image using Hough transform
void run_named_window();			// namedWindow() creates a window that can be used as a placeholder for images and trackbars
void run_move_window();				// move window to a specified location, what's so special here?...
void run_destroy_window();			// both destroyWindow and destroyAllWindows
void run_resize_window();			// resize window to specified size
void run_create_trackbar();			// create a trackbar and attach to a specific window, also callback function example
void run_get_trackbar_pos();		// getTrackbarPos() returns the current position of the specified trackbar
void run_set_mouse_callback();		// setMouseCallback() sets the mouse handler for the specified window
void run_select_roi();				// function to select a region of interest from a window, returns a rectangle with coordinates
void run_hconcat_vconcat();			// functions for vertical and horizontal concatenation of arrays
void run_merge_split();				// merge and split functions
void run_extract_channel();			// extract a channel from an image or Mat
void run_rotate();					// rotate a 2D array in multiples of 90 degrees
void run_flip();					// flip a 2D array around either or both horizontal and vertical axis
void run_count_non_zero();			// return the number of non-zero elements in an array
void run_insert_channel();			// insert a single channel to Matrix (coi is 0-based index)
void run_in_range();				// check if array elements lie between the elements of 2 other arrays or scalars
void run_mean();					// calculate the mean(arithmetic average) of all array elements
