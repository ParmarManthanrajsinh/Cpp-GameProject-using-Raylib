#include "game.hpp"

void Game::DrawBackground()
{
    if (bg_x1 <= -background_texture[0].width)
    {
        bg_x1 = background_texture[0].width;
    }
    if (bg_x2 <= -background_texture[1].width)
    {
        bg_x2 = background_texture[1].width;
    }
    bg_x1 -= bg_scroll_speed;
    bg_x2 -= bg_scroll_speed;

    DrawTexture(background_texture[0], bg_x1, bg_y1, WHITE);
    DrawTexture(background_texture[1], bg_x2, bg_y2, WHITE);
}

Game::Game() : flappybird(Vector2{135, 250})
{
    Image background = LoadImage("GameObjects/background-day.png");
    background_texture[0] = LoadTextureFromImage(background);
    background_texture[1] = LoadTextureFromImage(background);
    bg_x1 = 0;
    bg_y1 = 0;
    bg_x2 = GetScreenWidth();
    bg_y2 = 0;
    bg_scroll_speed = 1;
}

Game::~Game()
{
    UnloadTexture(background_texture[0]);
    UnloadTexture(background_texture[1]);
}

void Game::Draw()
{
    DrawBackground();
    flappybird.Draw();
}
