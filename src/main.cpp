
#include "identifier.hpp"

int main() {
    GridImage image;
    image.get_standard_grid("../images/standard_image.png");

    image.identify_map("../images/test.png");
    return 0;
}