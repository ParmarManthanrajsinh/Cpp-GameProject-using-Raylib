#include <iostream>
#include <raylib.h>

using namespace std;

/* Global Values */
const float offset = 31.3;
bool running = true;

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
        if (y + radius >= GetScreenHeight())
        {
            x = 360, y = 360;
            running = false;
        }
        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }
        if (y - radius <= 0)
        {
            speed_y *= -1;
        }
        x += speed_x;
        y += speed_y;
    }
};

class Player
{
public:
    float x = 310, y = 680;
    float width = 100, hight = 20;
    int speed = 7;

    void Draw()
    {
        DrawRectangle(x, y, width, hight, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_LEFT))
        {
            x -= speed;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            x += speed;
        }
        if (!running)
        {
            x = 310;
        }

        // Check player getting out of border
        if (x <= 0)
        {
            x = 0;
        }
        if (x + width >= GetScreenWidth())
        {
            x = GetScreenWidth() - width;
        }
    }
};

class Obstacle
{
public:
    float x = 0, y = 0;
    float width = offset, hight = offset;
    bool isHit = false;

    void SetPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void Draw()
    {
        if (!isHit)
        {
            DrawRectangle(x, y, width, hight, WHITE);
        }
    }

    void Update(Ball &ball)
    {
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{x, y, width, hight}) && !isHit)
        {
            ball.speed_y *= -1;
            isHit = true;
        }
    }
};

int main()
{
    const int SCREEN_WIDTH = 720;
    const int SCREEN_HEIGHT = 720;

    const int rows = 4;
    const int columns = 11;
    const int totalObstacles = rows * columns;

    Ball ball;
    Player player;
    Obstacle obstacles[totalObstacles];

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker Game");
    SetTargetFPS(60);

    // Set positions of all obstacles once
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            obstacles[index].SetPosition(offset + offset * 2 * j, offset + offset * 2 * i);
            index++;
        }
    }

    while (!WindowShouldClose())
    {
        if (running)
        { // Update logic
            ball.Update();
            player.Update();

            // Ball collision with the player
            if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.hight}))
            {
                ball.speed_y *= -1;
                ball.y = player.y - ball.radius; // Adjust the ball's position to prevent sticking
            }

            // Obstacle update
            for (int i = 0; i < totalObstacles; i++)
            {
                obstacles[i].Update(ball);
            }

            // Drawing
            BeginDrawing();
            ClearBackground(BLACK);

            // Draw obstacles
            for (int i = 0; i < totalObstacles; i++)
            {
                obstacles[i].Draw();
            }

            // Draw player and ball
            player.Draw();
            ball.Draw();

            EndDrawing();
        }
        else
        {
            BeginDrawing();
            ClearBackground(BLACK);

            DrawText("Game Over!", 260, 300, 40, RED);
            DrawText("Press any key to restart", 220, 360, 20, WHITE);

            for (int i = 0; i < totalObstacles; i++)
            {
                obstacles[i].isHit = false;
            }

            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || GetKeyPressed() != 0)
            {
                running = true;
            }
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
