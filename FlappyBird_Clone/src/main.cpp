#include <raylib.h>
#include "game.hpp"

int main()
{
    const int SCREEN_WIDTH = 288;
    const int SCREEN_HEIGHT = 512;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    InitAudioDevice();
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        game.Update();
        game.HandleInput();

        BeginDrawing();

        ClearBackground(BLACK);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}