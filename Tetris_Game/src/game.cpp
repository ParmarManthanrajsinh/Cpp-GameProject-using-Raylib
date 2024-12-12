#include "game.h"
#include <random>

void Game::RotateBlock()
{
    curr_block.Rotate();
    if (IsBlockOutside() || !BlockFits())
    {
        curr_block.UndoRotation();
    }
    else
    {
        PlaySound(rotatesound);
    }
}

void Game::LockBlock()
{
    vector<Position> tiles = curr_block.GetCellPosition();

    for (Position item : tiles)
    {
        grid.grid[item.row][item.col] = curr_block.id;
    }
    curr_block = next_block;
    if (!BlockFits())
    {
        gameover = true;
    }
    next_block = GetRandomBlock();
    int rowsclear = grid.ClearFullRows();
    if (rowsclear > 0)
    {
        PlaySound(clearsound);
        UpdateScore(rowsclear, 0);
    }
}

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    curr_block = GetRandomBlock();
    next_block = GetRandomBlock();
    gameover = false;
    score = 0;

    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotatesound = LoadSound("Sounds/rotate.mp3");
    clearsound = LoadSound("Sounds/clear.mp3");
}

Game::~Game()
{
    UnloadSound(rotatesound);
    UnloadSound(clearsound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

void Game::Draw()
{
    grid.Draw();
    curr_block.Draw(11, 11);
    if (next_block.id == 3)
    {
        next_block.Draw(255, 290);
    }
    else if (next_block.id == 4)
    {
        next_block.Draw(255, 280);
    }
    else
    {
        next_block.Draw(270, 270);
    }
}

void Game::HandleInput()
{
    int keypressed = GetKeyPressed();

    if (gameover && keypressed != 0)
    {
        gameover = false;
        Reset();
    }

    switch (keypressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomindex = rand() % blocks.size();
    Block block = blocks[randomindex];
    blocks.erase(blocks.begin() + randomindex);
    return block;
}

vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::MoveBlockLeft()
{
    if (!gameover)
    {
        curr_block.Move(0, -1);
        if (IsBlockOutside() || !BlockFits())
        {
            curr_block.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!gameover)
    {
        curr_block.Move(0, 1);
        if (IsBlockOutside() || !BlockFits())
        {
            curr_block.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameover)
    {
        curr_block.Move(1, 0);
        UpdateScore(0, 1);
        if (IsBlockOutside() || !BlockFits())
        {
            curr_block.Move(-1, 0);
            LockBlock();
            UpdateScore(0, -1);
        }
    }
}

bool Game::IsBlockOutside()
{
    vector<Position> tiles = curr_block.GetCellPosition();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}

bool Game::BlockFits()
{
    vector<Position> tiles = curr_block.GetCellPosition();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.col) == false)
        {
            return false;
        }
    }

    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    curr_block = GetRandomBlock();
    next_block = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int lineclear, int movedown)
{
    switch (lineclear)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
    case 3:
        score += 500;
    }
    score += movedown;
}
