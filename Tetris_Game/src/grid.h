#pragma once
#include <array>
#include <raylib.h>
using namespace std;

class Grid
{
private:
    int rows, cols;
    int cell_size;
    array<Color, 8> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int rows);

public:
    int grid[20][10];
    Grid();

    void Initialize();
    void Print();
    void Draw();
    int ClearFullRows();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
};
