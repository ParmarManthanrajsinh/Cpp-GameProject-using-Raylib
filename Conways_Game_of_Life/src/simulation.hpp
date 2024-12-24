#pragma once
#include "grid.hpp"

class Simulation
{
private:
    Grid grid;
    Grid tempgrid;

    bool run;

public:
    Simulation(int width, int hight, int cellsize) : grid(width, hight, cellsize), tempgrid(width, hight, cellsize)
    {
        run = false;
    }

    void Draw();
    void Update();
    void ClearGrid();
    void CreateRandomState();

    void ToggleCell(int row, int col);
    void SetCellValue(int row, int col, int value);
    int CountLivesNeighbors(int row, int col);

    void Start() { run = true; }
    void Stop() { run = false; }
    bool IsRunning() { return run; }
};
