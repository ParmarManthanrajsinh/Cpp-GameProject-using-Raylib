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
    hflip = false;

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

    // Define the source rectangle
    Rectangle sourceRect = {
        0.0f,
        0.0f,
        static_cast<float>(sprites[current_frame].width) * (hflip ? -1 : 1), // Flip horizontally if hflip is true
        static_cast<float>(sprites[current_frame].height)};

    // Define the destination rectangle
    Rectangle destRect = {
        position.x,
        position.y,
        sprites[current_frame].width * scale,
        sprites[current_frame].height * scale};

    // Define the origin for rotation (center of the sprite)
    Vector2 origin = {sprites[current_frame].width / 2.0f, sprites[current_frame].height / 2.0f};

    // Draw the texture
    DrawTexturePro(sprites[current_frame], sourceRect, destRect, origin, rotation, WHITE);
}
