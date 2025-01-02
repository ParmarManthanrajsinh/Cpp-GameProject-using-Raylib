#include "flappybird.hpp"

FlappyBird::FlappyBird(Vector2 pos) : bird(position, vector<Image>{LoadImage("GameObjects/yellowbird-downflap.png"), LoadImage("GameObjects/yellowbird-midflap.png"), LoadImage("GameObjects/yellowbird-upflap.png")}, 0.2, true)
{
    position = pos;
    bird.scale = 1.5;
    IsHit = false;
    bird_hitbox = {position.x, position.y, 34 * 1.5, 24 * 1.5};
}

void FlappyBird::Draw()
{
    bird.Draw();
    // Debug
    // DrawRectangle(bird_hitbox.x, bird_hitbox.y, bird_hitbox.width, bird_hitbox.height, RED);
}

void FlappyBird::Update()
{
    if (position.y >= 485)
    {
        position.y = 485;
        IsHit = true;
        bird.IsAnimation = false;
    }
    else
    {
        position.y += (IsHit) ? 6 : 2;

        bird.SetPosition(position);
        bird.rotation += 0.5;

        if (position.y < 0)
        {
            IsHit = true;
            bird.IsAnimation = false;
        }
    }
    bird_hitbox.x = position.x;
    bird_hitbox.y = position.y;
}

void FlappyBird::Jump()
{
    if (!IsHit)
    {
        position.y -= 50;
        bird.SetPosition(position);
        bird.rotation = -40;
    }
}
