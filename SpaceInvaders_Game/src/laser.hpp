#pragma once
#include <raylib.h>

class Laser
{
private:
    Vector2 position;
    int speed;
public:
    bool active;
    Laser(Vector2 position, int speed);

    void Draw();
    void Update();
    Rectangle GetRect();
};