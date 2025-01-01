#pragma once
#include <raylib.h>
#include "flappybird.hpp"

class Game
{
private:
    Texture2D background_texture[2];
    int bg_x1, bg_y1;
    int bg_x2, bg_y2;
    int bg_scroll_speed;
    void DrawBackground();

    FlappyBird flappybird;

public:
    Game();
    ~Game();
    
    void Draw();
    void Update();
    void HandleInput();
};