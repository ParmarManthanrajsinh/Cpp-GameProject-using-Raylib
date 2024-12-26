#include "sprite.hpp"

double lastUpdateTime = 0;

bool Delay(double intervel)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= intervel)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

Sprite::Sprite(Vector2 pos, vector<Image> images, double animationSpeed, bool looping)
{
    IsAnimation = true;
    loop = looping;

    position = pos;
    total_no_frames = images.size();
    current_frame = 0;

    scale = 1.0;
    rotation = 0.0;

    animation_speed = animationSpeed;

    for (int i = 0; i < total_no_frames; i++)
    {
        Texture2D texture = LoadTextureFromImage(images[i]);
        sprites.push_back(texture);
    }
}

Sprite::~Sprite()
{
    for (int i = 0; i < total_no_frames; i++)
    {
        UnloadTexture(sprites[i]);
    }
}

void Sprite::Draw()
{
    if (IsAnimation && Delay(animation_speed))
    {
        if (current_frame < total_no_frames - 1)
        {
            current_frame++;
        }
        else if (loop)
        {
            current_frame = 0; // Restart animation
        }
    }
    // Draw only the current frame
    DrawTextureEx(sprites[current_frame], {position.x, position.y}, rotation, scale, WHITE);
}
