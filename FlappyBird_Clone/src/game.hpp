#pragma once

#include <raylib.h>
#include "flappybird.hpp"
#include "pipe_generator.hpp"
class Game
{
private:
    Texture2D background_texture[2];
    int bg_x1, bg_y1;
    int bg_x2, bg_y2;
    int bg_scroll_speed;
    void DrawBackground();

    FlappyBird flappybird;
    PipeGenerator pipe_generator;

public:
    Game();
    ~Game();

    bool run;

    void Draw();
    void Update();
    void Reset();
    void HandleInput();
};