#include "colors.h"

const Color grey = {26, 31, 40, 255};
const Color cyan = {0, 255, 255, 255};

std::array<Color, 8> GetCellColor()
{
    return {grey, RED, BLUE, GREEN, ORANGE, YELLOW, cyan, PURPLE};
}
