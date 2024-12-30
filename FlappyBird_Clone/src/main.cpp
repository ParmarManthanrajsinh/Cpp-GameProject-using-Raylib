#include <raylib.h>
#include "game.hpp"

int main()
{
    const int SCREEN_WIDTH = 288;
    const int SCREEN_HEIGHT = 512;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}