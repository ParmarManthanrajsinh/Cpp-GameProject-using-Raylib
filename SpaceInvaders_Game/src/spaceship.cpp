#include "spaceship.hpp"

SpaceShip::SpaceShip()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 100;
    lastfiretime = 0.0;
    laser = LoadSound("Sounds/laser.ogg");
}

SpaceShip::~SpaceShip()
{
    UnloadTexture(image);
    UnloadSound(laser);
}

void SpaceShip::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void SpaceShip::MoveLeft()
{
    position.x -= 7;

    if (position.x < 25)
    {
        position.x = 25;
    }
}

void SpaceShip::MoveRight()
{
    position.x += 7;

    if (position.x > (GetScreenWidth() - image.width - 25))
    {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void SpaceShip::FireLaser()
{
    if (GetTime() - lastfiretime >= 0.35)
    {
        lasers.push_back(Laser({position.x + (image.width / 2) - 2, position.y}, -6));
        lastfiretime = GetTime();
        PlaySound(laser);
    }
}

void SpaceShip::Reset()
{
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}

Rectangle SpaceShip::GetRect()
{
    return {position.x, position.y, static_cast<float>(image.width), static_cast<float>(image.height)};
}
