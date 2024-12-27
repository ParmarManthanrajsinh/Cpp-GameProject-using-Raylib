#pragma once
#include <raylib.h>
#include "sprite.hpp"

class Character
{
private:
    Vector2 position;

    int speed;

    Sprite Idle;
    Sprite Walk;

    enum State
    {
        IDLE,
        WALK_LEFT,
        WALK_RIGHT,
    } state;

public:
    Character(Vector2 pos);

    void Draw();
    void HandleInput();
    void SetPosition(Vector2 newPosition) { position = newPosition; }
    const Vector2 GetPosition() { return position; }
};