#include <iostream>
#include <raylib.h>

using namespace std;

/* Global Values */
const float offset = 30;
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
        DrawRectangle(x, y, width, hight, GREEN);
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
    float x, y;
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
            DrawRectangle(x, y, width, hight, GREEN);
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

void GenrateObstacles(int row, int column, int total, Obstacle obstacles[])
{
    // Set positions of all obstacles once
    int index = 0;
    for (int i = 0; i < row; i++)
    {
        int value = GetRandomValue(0, 3);
        if (value == 0)
        {
            continue;
        }

        for (int j = 0; j < column; j++)
        {
            if (value == 0)
            {
                continue;
            }
            obstacles[index].SetPosition((offset + 10) * j, (offset + 10) * i);
            index++;
        }
    }
}

int main()
{
    const int SCREEN_WIDTH = 720;
    const int SCREEN_HEIGHT = 720;

    Ball ball;
    Player player;

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Brick Breaker Game");
    SetTargetFPS(60);

    const int rows = 8;
    const int columns = 18;
    const int totalObstacles = rows * columns;
    Obstacle obstacles[totalObstacles];

    GenrateObstacles(rows, columns, totalObstacles, obstacles);

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

            GenrateObstacles(rows, columns, totalObstacles, obstacles);

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
