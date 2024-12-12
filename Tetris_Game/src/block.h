#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block
{
private:
    int cell_size;
    int rotation_state;
    vector<Color> colors;
    int rowoffset;
    int coloffset;

public:
    int id;
    map<int, vector<Position>> cells;

    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int,int);
    void Rotate();
    void UndoRotation();
    vector<Position> GetCellPosition();
};