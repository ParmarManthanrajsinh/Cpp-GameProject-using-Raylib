#include <raylib.h>
#include <iostream>
#include "game.h"

double lastupdatetime = 0;

/* Debuging code */
// static int alloc_count = 0;
// void *operator new(size_t size)
// {
//     cout << "Allocating " << size << " bytes" << endl;
//     alloc_count++;
//     return malloc(size);
// }

bool Delay(double time)
{
    double curr_time = GetTime();
    if (curr_time - lastupdatetime >= time)
    {
        lastupdatetime = curr_time;
        return true;
    }
    return false;
}

int main()
{
    int x_offset = 200, y_offset = 20;
    constexpr int screenWidth = 300;
    constexpr int screenHeight = 600;
    Color darkBlue = {28, 28, 163, 255};

    Game game = Game();

    InitWindow(screenWidth + x_offset, screenHeight + y_offset, "Tetris Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();

        if (Delay(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(darkBlue);
        DrawText("Score", 350, 15, 38, WHITE);
        DrawText("Next", 355, 175, 38, WHITE);
        if (game.gameover)
        {
            DrawText("GameOver", 330, 475, 32, WHITE);
        }

        char score_text[10];
        sprintf(score_text, "%d", game.score);
        int textsize = MeasureText(score_text, 38);

        DrawRectangleRounded({320, 55, 170, 60}, 0.2, 1, grey);
        DrawText(score_text, 320 + (170 - textsize) / 2, 70, 38, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.2, 1, grey);
        game.Draw();

        EndDrawing();
    }

    /* Debuging code */
    // cout << "Allocations: " << alloc_count << endl;
    // cout << "Copies: " << Block::copy_count << endl;

    CloseWindow();
}