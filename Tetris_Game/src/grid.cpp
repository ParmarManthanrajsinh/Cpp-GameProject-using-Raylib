#include <iostream>
#include "grid.h"
#include "colors.h"

bool Grid::IsRowFull(int row)
{
    for (int col = 0; col < cols; col++)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int col = 0; col < cols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int rows)
{
    for (int col = 0; col < cols; col++)
    {
        grid[row + rows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

Grid::Grid()
{
    rows = 20;
    cols = 10;
    cell_size = 30;
    Initialize();
    colors = GetCellColor();
}

void Grid::Initialize()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int cell_value = grid[row][col];
            DrawRectangle(col * cell_size + 11, row * cell_size + 11, cell_size - 1, cell_size - 1, colors[cell_value]);
        }
    }
}

int Grid::ClearFullRows()
{
    int completed_rows = 0;

    for (int row = rows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed_rows++;
        }
        else if (completed_rows > 0)
        {
            MoveRowDown(row, completed_rows);
        }
    }

    return completed_rows;
}

bool Grid::IsCellOutside(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return false;
    }

    return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if (grid[row][col] == 0)
    {
        return true;
    }
    return false;
}
