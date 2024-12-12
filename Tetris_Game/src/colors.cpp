#include "colors.h"

const Color grey = {26, 31, 40, 255};
const Color red = {255, 0, 0, 255};
const Color blue = {0, 0, 255, 255};
const Color green = {0, 255, 0, 255};
const Color orange = {255, 165, 0, 255};
const Color yellow = {255, 255, 0, 255};
const Color cyan = {0, 255, 255, 255};
const Color purple = {128, 0, 128, 255};

std::vector<Color> GetCellColor()
{
    return {grey, RED, BLUE, GREEN, ORANGE, YELLOW, cyan, PURPLE};
}