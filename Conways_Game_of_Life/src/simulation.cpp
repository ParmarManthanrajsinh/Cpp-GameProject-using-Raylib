#include "simulation.hpp"
#include <utility>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::Update()
{
    if (IsRunning())
    {
        for (int row = 0; row < grid.GetRows(); row++)
        {
            for (int col = 0; col < grid.GetCols(); col++)
            {
                int live_neighbors = CountLivesNeighbors(row, col);
                int cell_value = grid.GetValue(row, col);

                if (cell_value == 1)
                {
                    if (live_neighbors > 3 || live_neighbors < 2)
                    {
                        tempgrid.SetValue(row, col, 0);
                    }
                    else
                    {
                        tempgrid.SetValue(row, col, 1);
                    }
                }
                else
                {
                    if (live_neighbors == 3)
                    {
                        tempgrid.SetValue(row, col, 1);
                    }
                    else
                    {
                        tempgrid.SetValue(row, col, 0);
                    }
                }
            }
        }
        grid = tempgrid;
    }
}

void Simulation::ClearGrid()
{
    if (!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if (!IsRunning())
    {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int col)
{
    if (!IsRunning())
    {
        grid.ToggleCell(row, col);
    }
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLivesNeighbors(int row, int col)
{
    int liveneighbors = 0;

    vector<pair<int, int>> neighbors_offset = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };

    for (const auto &offset : neighbors_offset)
    {
        int neighbor_row = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighbor_col = (col + offset.second + grid.GetCols()) % grid.GetCols();
        liveneighbors += grid.GetValue(neighbor_row, neighbor_col);
    }
    return liveneighbors;
}
