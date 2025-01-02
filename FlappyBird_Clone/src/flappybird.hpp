#pragma once
#include "sprite.hpp"

class FlappyBird
{
private:
    Vector2 position;
    Sprite bird;

public:
    FlappyBird(Vector2 pos);

    Rectangle bird_hitbox;
    bool IsHit;

    void Draw();
    void Update();
    void Jump();
};
