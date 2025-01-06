#include "game.hpp"

void Game::DrawBackground()
{
    if (run)
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
    }

    DrawTexture(background_texture[0], bg_x1, bg_y1, WHITE);
    DrawTexture(background_texture[1], bg_x2, bg_y2, WHITE);
}

Game::Game() : flappybird(Vector2{135, 250})
{
    run = true;
    Image background = LoadImage("GameObjects/background-day.png");
    background_texture[0] = LoadTextureFromImage(background);
    background_texture[1] = LoadTextureFromImage(background);
    UnloadImage(background);
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
    pipe_generator.Draw();

    DrawText(TextFormat("%d", pipe_generator.pipe_spawn_counter), 140, 50, 30, WHITE);
}

void Game::Update()
{
    flappybird.Update();

    if (run)
    {
        pipe_generator.Update();

        if (pipe_generator.CheckCollision(flappybird.bird_hitbox) || flappybird.IsHit)
        {
            flappybird.IsHit = true;
            run = false;
            // PlaySound(hit_sound);
            // PlaySound(die_sound);
        }
    }
}

void Game::Reset()
{
    run = true;
    flappybird.Reset(Vector2{135, 250});
    pipe_generator.Reset();
}

void Game::HandleInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        flappybird.Jump();
    }
    if (IsKeyDown(KEY_ENTER) && !run)
    {
        Reset();
    }
}
