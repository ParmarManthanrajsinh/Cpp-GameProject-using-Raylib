#include "flappybird.hpp"

FlappyBird::FlappyBird(Vector2 pos)
{
    position = pos;
    bird = new Sprite(position, vector<Image>{LoadImage("GameObjects/yellowbird-downflap.png"), LoadImage("GameObjects/yellowbird-midflap.png"), LoadImage("GameObjects/yellowbird-upflap.png")}, 0.2, true);
    bird->scale = 1.5;
    IsHit = false;
}

FlappyBird::~FlappyBird()
{
    delete bird;
}

void FlappyBird::Draw()
{
    bird->Draw();
}

void FlappyBird::Update()
{
    if (position.y >= 485)
    {
        position.y = 485;
        IsHit = true;
        bird->IsAnimation = false;
    }
    else
    {
        position.y += (IsHit) ? 5 : 1;

        bird->SetPosition(position);
        bird->rotation += 0.5;

        if (position.y < 0)
        {
            IsHit = true;
            bird->IsAnimation = false;
        }
    }
}

void FlappyBird::Jump()
{
    if (!IsHit)
    {
        position.y -= 50;
        bird->SetPosition(position);
        bird->rotation = -40;
    }
}
