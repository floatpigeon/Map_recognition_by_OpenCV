
#include "identifier.hpp"

int main() {
    GridImage image;
    image.get_standard_grid("../include/images/standard_image.png");

    image.identify_map("../include/images/test.png");
    return 0;
}