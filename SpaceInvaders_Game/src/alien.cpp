#include "alien.hpp"

Alien::Alien(int type, Vector2 pos)
{
    this->type = type;
    position = pos;

    if (Alien::alienimages[type - 1].id == 0)
    {
        switch (type)
        {
        case 1:
            alienimages[0] = LoadTexture("Graphics/alien_1.png");
            break;

        case 2:
            alienimages[1] = LoadTexture("Graphics/alien_2.png");
            break;

        case 3:
            alienimages[2] = LoadTexture("Graphics/alien_3.png");
            break;

        default:
            alienimages[0] = LoadTexture("Graphics/alien_1.png");
            break;
        }
    }
}

Texture2D Alien::alienimages[3] = {};

void Alien::Draw()
{
    DrawTextureV(alienimages[type - 1], position, WHITE);
}

void Alien::Update(int direction)
{
    position.x += direction;
}

int Alien::GetType()
{
    return type;
}

Rectangle Alien::GetRect()
{
    return Rectangle{position.x, position.y, static_cast<float>(alienimages[type - 1].width), static_cast<float>(alienimages[type - 1].height)};
}

void Alien::UnloadAlienImages()
{
    for (int i = 0; i < 3; i++)
    {
        UnloadTexture(alienimages[i]);
    }
}
