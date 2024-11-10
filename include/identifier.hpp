#pragma once

#include <opencv4/opencv2/opencv.hpp>
#include <vector>

class GridImage {
public:
    bool get_standard_grid(const std::string name);
    std::vector<std::vector<int>> identify_map(const std::string name);

private:
    double grid_H, grid_W;
};

/*
OPenCV 坐标系：
    横为x竖为y
    与二维数组坐标刚好转置
*/