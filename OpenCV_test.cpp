// OpenCV_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2\opencv.hpp>
#include "opencv_test.h"


int get_abs_length(const int& startPoint, const int& endPoint) {
    return std::abs(endPoint - startPoint);
}

cv::Rect get_normalized_rect_from_points(const int& x1, const int& y1, const int& x2, const int& y2) {
    int width = get_abs_length(x1, x2);
    int height = get_abs_length(y1, y2);

    if (x2 <= x1 && y1 <= y2) {
        return cv::Rect(x2, y1, width, height);
    }
    else if (x2 <= x1 && y2 <= y1) {
        return cv::Rect(x2, y2, width, height);
    }
    else if (x1 <= x2 && y1 <= y2) {
        return cv::Rect(x1, y1, width, height);
    }
    else {
        return cv::Rect(x1, y2, width, height);
    }
}

cv::Rect normalize_rect(const cv::Rect& r) {
    int x1 = r.x;
    int y1 = r.y;
    int x2 = r.x + r.width;
    int y2 = r.y + r.height;

    return get_normalized_rect_from_points(x1, y1, x2, y2);
}

cv::Mat downscale_image(const cv::Mat& img, const int& maxSize) {
    cv::Mat returnImg = img.clone();
    int scaleFactor = 1;
    int xMax = maxSize;
    int yMax = maxSize;

    while (returnImg.rows > yMax || returnImg.cols > xMax) {
        scaleFactor *= 2;

        cv::resize(returnImg, returnImg, cv::Size(img.cols / scaleFactor, img.rows / scaleFactor));
    }

    return returnImg;
}


int main(int argc, char *argv[])
{
    //run_blur_filters();
    //run_conv_filters();
    //run_sobel_filter();
    //run_laplacian();
    //run_drawing_methods_I();
    //run_drawing_methods_II();
    //run_image_contour_drawing();
    //run_resize();
    //run_warp_perspective();
    //run_affine_transform();
    //run_rotation();
    //run_data_types();
    //run_convert_maps();
    //run_remap();
    //run_polar_transformations();
    //run_rectangle_sub_pixel();
    //run_threshold();
    //run_adaptive_threshold();
    //run_integral();
    //run_distance_transform();
    //run_blend_linear();
    //run_grab_cut();
    //run_watershed();
    //run_flood_fill();
    //run_cvt_color();
    //run_cvt_color_two_plane();
    //run_demosaicing();
    //run_apply_color_map();
    //run_equalize_histogram();
    //run_calculate_histogram();
    //run_compare_histogram();
    //run_calculate_back_project();
    //show_squares();
    //run_emd();
    //run_clahe();
    //run_find_contours();
    //run_bounding_rect();
    //run_min_area_rect();
    //run_min_enclosing_circle();
    //run_min_enclosing_triangle();
    //run_contour_convex();
    //run_arc_length();
    //run_approx_poly_dp();
    //run_convex_hull();
    //run_fit_line();
    //run_rotated_rect_intersect();
    //run_connected_components();
    //run_intersect_convex_convex();
    //run_contour_area();
    //run_point_polygon_test();
    //run_moments();
    //run_hu_moments();
    //run_match_shapes();
    //run_canny();
    //run_corner_harris();
    //run_corner_eigen_val_vect();
    //run_green_detection_mask();
    //run_good_features_to_track();
    //run_hough_circles();
    //run_hough_lines();
    //run_named_window();
    //run_move_window();
    //run_destroy_window();
    //run_resize_window();
    //run_create_trackbar();
    //run_get_trackbar_pos();
    //run_set_mouse_callback();
    //run_select_roi();
    //run_hconcat_vconcat();
    //run_merge_split();
    //run_extract_channel();
    //run_rotate();
    //run_flip();
    //run_count_non_zero();
    //run_insert_channel();
    //run_in_range();
    //run_mean();
    //run_compare();
    //run_find_non_zero();
    //run_complete_symm();
    //run_min_max();
    //run_pow();
    //run_multiply();
    //run_transpose();
    //run_add();
    //run_add_weighted();
    //run_divide();
    //run_lines_contours();
    //run_test_1();
    //run_mean_std_dev();
    //run_determinant();
    //run_min_max_loc();
    //run_min_max_idx();
    //run_exp();
    //run_convert_scale_abs();
    //run_invert();
    //run_eigen();
    //run_bitwise_ops();
    //run_shi_thomasi();
    //run_check_range();
    //run_log();
    //run_psnr();
    //run_normalize();
    //run_randn();
    //run_repeat();
    //run_sort();
    //run_solve();
    //run_dct();
    //run_dft();
    //run_magnitude();
    //run_fit_ellipse();
    run_watershed_corners();

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
