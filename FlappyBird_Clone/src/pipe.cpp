#include "pipe.hpp"

Pipe::Pipe(Vector2 position, int speed, bool flip)
{
    if (flip)
    {
        Image pipe_image = LoadImage("GameObjects/pipe-green-flip.png");
        pipe_texture = LoadTextureFromImage(pipe_image);
        UnloadImage(pipe_image);
    }
    else
    {
        Image pipe_image = LoadImage("GameObjects/pipe-green.png");
        pipe_texture = LoadTextureFromImage(pipe_image);
        UnloadImage(pipe_image);
    }
    this->position = position;
    this->speed = speed;
    this->flip = flip;

    pipe_hitbox = {position.x + 2, position.y, 52 - 4, 320};
}

Pipe::~Pipe()
{
    UnloadTexture(pipe_texture);
}

void Pipe::Draw()
{
    DrawTexture(pipe_texture, position.x, position.y, WHITE);
    // Debug
    // DrawRectangle(pipe_hitbox.x, pipe_hitbox.y, pipe_hitbox.width, pipe_hitbox.height, RED);
}

void Pipe::Update()
{
    position.x -= speed;
    pipe_hitbox.x -= speed;
}

bool Pipe::IsOffScreen()
{
    if (position.x < 0)
    {
        return true;
    }
    return false;
}
