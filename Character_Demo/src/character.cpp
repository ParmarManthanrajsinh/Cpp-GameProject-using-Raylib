#include "character.hpp"
#include <vector>

Character::Character(Vector2 pos)
{
    Idle = new Sprite(pos, {LoadImage("Sprites/Enemy-Punk/Idle/idle1.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle2.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle3.png"), LoadImage("Sprites/Enemy-Punk/Idle/idle4.png")}, 0.2, true);

    Walk = new Sprite(pos, {LoadImage("Sprites/Enemy-Punk/Walk/walk1.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk2.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk3.png"), LoadImage("Sprites/Enemy-Punk/Walk/walk4.png")}, 0.2, true);
    
    Punch = new Sprite(pos, {LoadImage("Sprites/Enemy-Punk/Punch/punch1.png"), LoadImage("Sprites/Enemy-Punk/Punch/punch2.png"), LoadImage("Sprites/Enemy-Punk/Punch/punch3.png")}, 0.2, true);
    position = pos;

    Idle->scale = 2;
    Walk->scale = 2;
    Punch->scale = 2;

    speed = 2;

    state = IDLE;
}

Character::~Character()
{
    free(Idle);
    free(Walk);
    free(Punch);
}

void Character::Draw()
{
    Idle->SetPosition(position);
    Walk->SetPosition(position);
    Punch->SetPosition(position);

    switch (state)
    {
    case IDLE:
        Idle->Draw();
        break;

    case WALK_LEFT:
        Walk->hflip = false;
        Idle->hflip = false;
        Punch->hflip = false;
        Walk->Draw();
        break;

    case WALK_RIGHT:
        Walk->hflip = true;
        Idle->hflip = true;
        Punch->hflip = true;
        Walk->Draw();
        break;

    case PUNCH:
        Punch->Draw();
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
    else if (IsKeyDown(KEY_W))
    {
        state = PUNCH;
    }
    else
    {
        state = IDLE;
    }
}
