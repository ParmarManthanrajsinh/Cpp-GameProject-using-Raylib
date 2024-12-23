#include <raylib.h>
#include "ball.h"

int main()
{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    Ball ball;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        ball.Update();

        BeginDrawing();

        ClearBackground(BLACK);
        ball.Draw();

        EndDrawing();
    }

    CloseWindow();
}