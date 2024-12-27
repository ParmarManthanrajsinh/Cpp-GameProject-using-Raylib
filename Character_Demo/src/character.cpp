#include "character.hpp"
#include <vector>

Character::Character(Vector2 pos)
    : Idle(pos, {LoadImage("Sprites/Enemy-Punk/Idle/idle1.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle2.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle3.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle4.png")}, 0.2, true),
      Walk(pos, {LoadImage("Sprites/Enemy-Punk/Walk/walk1.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk2.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk3.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk4.png")}, 0.2, true)
{
    position = pos;

    Idle.scale = 2;
    Walk.scale = 2;

    speed = 2;

    state = IDLE;
}

void Character::Draw()
{
    Idle.SetPosition(position);
    Walk.SetPosition(position);

    switch (state)
    {
    case IDLE:
        Idle.Draw();
        break;
    case WALK_LEFT:
        Walk.hflip = false;
        Idle.hflip = false;
        Walk.Draw();
        break;
    case WALK_RIGHT:
        Walk.hflip = true;
        Idle.hflip = true;
        Walk.Draw();
        break;
    }
}

void Character::HandleInput()
{
    if (IsKeyDown(KEY_A))
    {
        state = WALK_LEFT;
        position.x -= speed;
    }
    else if (IsKeyDown(KEY_D))
    {
        state = WALK_RIGHT;
        position.x += speed;
    }
    else
    {
        state = IDLE;
    }
}
