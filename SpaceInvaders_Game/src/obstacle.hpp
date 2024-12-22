#pragma once

#include <vector>
#include "block.hpp"

class Obstacle
{
private:
public:
    Vector2 position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;

    Obstacle(Vector2 pos);
    void Draw();
};
