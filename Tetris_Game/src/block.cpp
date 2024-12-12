#include "block.h"

Block::Block()
{
    cell_size = 30;
    rotation_state = 0;
    colors = GetCellColor();
    rowoffset = 0;
    coloffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    vector<Position> titles = GetCellPosition();

    for (Position item : titles)
    {
        DrawRectangle(item.col * cell_size + offsetX, item.row * cell_size + offsetY, cell_size - 1, cell_size - 1, colors[id]);
    }
}

void Block::Move(int rows, int cols)
{
    rowoffset += rows;
    coloffset += cols;
}

void Block::Rotate()
{
    rotation_state++;

    if (rotation_state == int(cells.size()))
    {
        rotation_state = 0;
    }
}

void Block::UndoRotation()
{
    rotation_state--;

    if (rotation_state == -1)
    {
        rotation_state = int(cells.size()) - 1;
    }
}

vector<Position> Block::GetCellPosition()
{
    vector<Position> tiles = cells[rotation_state];
    vector<Position> movetiles;

    for (Position item : tiles)
    {
        Position newpos = Position(item.row + rowoffset, item.col + coloffset);
        movetiles.push_back(newpos);
    }
    return movetiles;
}
