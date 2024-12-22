#pragma once
#include <raylib.h>

class MysteryShip
{
private:
    Vector2 position;
    Texture2D image;
    int speed;

public:
    MysteryShip();
    ~MysteryShip();

    bool alive;
    void Draw();
    void Update();
    void Spawn();
    Rectangle GetRect();
};
