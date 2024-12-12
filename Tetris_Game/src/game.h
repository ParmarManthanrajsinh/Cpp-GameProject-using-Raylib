#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
private:
    std::vector<Block> blocks;
    Block curr_block;
    Block next_block;

    void RotateBlock();
    void LockBlock();
    void Reset();
    void UpdateScore(int lineclear, int movedown);
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockOutside();
    bool BlockFits();

    Sound rotatesound;
    Sound clearsound;

    Grid grid = Grid();
    Block GetRandomBlock();
    vector<Block> GetAllBlocks();
     
public:
    bool gameover;
    int score;
    Music music;

    Game();
    ~Game();

    void Draw();
    void HandleInput();
    void MoveBlockDown();

};