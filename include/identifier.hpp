#pragma once

#include <opencv4/opencv2/opencv.hpp>

class GridImage {
public:
    bool get_standard_grid();

private:
    double grid_H, grid_W;
};