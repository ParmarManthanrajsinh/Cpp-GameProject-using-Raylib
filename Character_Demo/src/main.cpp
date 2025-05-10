#include <raylib.h>
#include "character.hpp"

int main()
{
    constexpr int SCREEN_WIDTH = 1280;
    constexpr int SCREEN_HEIGHT = 720;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Character Demo");
    SetTargetFPS(60);

    Character character({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2});

    while (!WindowShouldClose())
    {
        character.HandleInput();

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("A/D Move Left Right  |  W Punch", 40, 40, 40, PURPLE);
        character.Draw();

        EndDrawing();
    }

    CloseWindow();
}