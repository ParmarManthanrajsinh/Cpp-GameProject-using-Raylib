#pragma once

#include <raylib.h>
#include <vector>
#include "laser.hpp"

class SpaceShip
{
private:
    Texture2D image;
    Vector2 position;
    double lastfiretime;
    Sound laser;

public:
    std::vector<Laser> lasers;

    SpaceShip();
    ~SpaceShip();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();
    void Reset();

    Rectangle GetRect();
};