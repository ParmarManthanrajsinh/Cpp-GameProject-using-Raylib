#include <iostream>
#include <raylib.h>

using namespace std;

class Ball
{
public:
    float x = 360, y = 360;
    int speed_x = 5, speed_y = 5;
    int radius = 15;

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }
        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        x += speed_x;
        y += speed_y;
    }
};

int main()
{

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    Ball ball;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        ball.Update();
        ball.Draw();

        EndDrawing();
    }

    CloseWindow();
}