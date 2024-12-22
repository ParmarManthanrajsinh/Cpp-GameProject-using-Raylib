#pragma once
#include <raylib.h>

class Block
{
private:
    Vector2 position;
public:
    Block(Vector2 pos);
    void Draw();
    Rectangle GetRect();
};
