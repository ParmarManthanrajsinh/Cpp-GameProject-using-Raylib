#pragma once
#include "sprite.hpp"

class FlappyBird
{
private:
    Vector2 position;
    Sprite *bird;

public:
    FlappyBird(Vector2 pos);
    ~FlappyBird();
    void Draw();
};
