#include "grid.hpp"

void Grid::Draw()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Color color = cells[i][j] ? GREEN : BLACK;
            DrawRectangle(j * cell_size, i * cell_size, cell_size - 1, cell_size - 1, color);
        }
    }
}

void Grid::FillRandom()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int random_value = GetRandomValue(0, 4);
            cells[i][j] = (random_value == 4) ? 1 : 0;
        }
    }
}

void Grid::Clear()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cells[i][j] = 0;
        }
    }
}

void Grid::ToggleCell(int row, int col)
{
    if (IsWithinBounds(row, col))
    {
        cells[row][col] = !cells[row][col];
    }
}

void Grid::SetValue(int row, int col, int value)
{
    if (IsWithinBounds(row, col))
    {
        cells[row][col] = value;
    }
}

int Grid::GetValue(int row, int col)
{
    if (IsWithinBounds(row, col))
    {
        return cells[row][col];
    }
    return 0;
}

bool Grid::IsWithinBounds(int row, int col)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
        return true;
    else
        return false;
}
