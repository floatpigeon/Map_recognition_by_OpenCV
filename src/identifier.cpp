#include "identifier.hpp"

#include <opencv2/calib3d.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>

bool GridImage::get_standard_grid() {
    cv::Mat standard_image = cv::imread("../include/images/standard_image.png");
    if (standard_image.empty()) {
        std::cout << "can't find standard iamge" << std::endl;
        return false;
    }
    cv::Mat gray;
    cv::cvtColor(standard_image, gray, cv::COLOR_BGR2GRAY);

    cv::Size patternSize(11, 11);
    std::vector<cv::Point2f> corners;
    bool found = cv::findChessboardCorners(gray, patternSize, corners);

    if (!found) {
        std::cout << "No corners" << std::endl;
        return false;
    }

    cv::cornerSubPix(gray, corners, cv::Size(11, 11), cv::Size(-1, -1),
                     cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));

    int num_h = 0;
    int num_w = 0;
    double sum_h = 0;
    double sum_w = 0;

    for (int i = 0; i < patternSize.height - 1; ++i) {
        for (int j = 0; j < patternSize.width - 1; ++j) {
            int idx = i * patternSize.width + j;
            double height = cv::norm(corners[idx + patternSize.width] - corners[idx]);
            double width = cv::norm(corners[idx + 1] - corners[idx]);

            sum_h += height;
            sum_w += width;

            num_h++;
            num_w++;
        }
    }
    grid_H = sum_h / num_h;
    grid_W = sum_w / num_w;

    std::cout << "height " << grid_H << "points" << std::endl;
    std::cout << "width " << grid_W << "points" << std::endl;

    cv::drawChessboardCorners(standard_image, patternSize, cv::Mat(corners), found);
    cv::imshow("Chessboard Corners", standard_image);
    if (cv::waitKey(0) == 'q') {
        cv::destroyAllWindows();
    }
    return true;
}