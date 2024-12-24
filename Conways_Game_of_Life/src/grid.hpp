#pragma once

#include <vector>
#include <raylib.h>

using namespace std;

class Grid
{
private:
    int rows;
    int cols;
    int cell_size;
    vector<vector<int>> cells;

public:
    Grid(int width, int hight, int cellsize) : rows(hight / cellsize), cols(width / cellsize), cell_size(cellsize), cells(rows, vector<int>(cols, 0)) {};

    void Draw();
    void FillRandom();
    void Clear();

    void ToggleCell(int row, int col);

    void SetValue(int row, int col, int value);
    int GetValue(int row, int col);

    int GetRows()
    {
        return rows;
    }
    int GetCols()
    {
        return cols;
    }

    bool IsWithinBounds(int row, int col);
};