#include <raylib.h>
#include "character.hpp"

int main()
{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Character Demo");
    SetTargetFPS(60);

    Character character({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

    while (!WindowShouldClose())
    {
        character.HandleInput();

        BeginDrawing();

        ClearBackground(BLACK);
        character.Draw();

        EndDrawing();
    }

    CloseWindow();
}