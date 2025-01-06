#pragma once
#include "sprite.hpp"

class FlappyBird
{
private:
    Vector2 position;
    Sprite bird;    
    Sound wing_sound;   

public:
    FlappyBird(Vector2 pos);
    ~FlappyBird();

    Rectangle bird_hitbox;
    bool IsHit;

    void Draw();
    void Update();
    void Jump();
    void Reset(Vector2 pos);
};
