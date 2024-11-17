#include <iostream>
#include <raylib.h>

using namespace std;

int player_score = 0;
int cpu_score = 0;

Color Red_light = Color{227, 50, 50, 255};
Color Red_dark = Color{171, 14, 14, 255};

class Ball
{
public:
    float x, y;
    int speed_x = 7, speed_y = 7;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE); // Draw Circle
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;

        // Checking if ball has hit the wall
        if ((y + radius >= GetScreenHeight()) || (y - radius <= 0))
        {
            speed_y *= -1;
        }
        if (x + radius >= GetScreenWidth())
        {
            player_score++;
            ResetBall();
            // cout << "player: " << player_score << endl;
        }
        if (x - radius <= 0)
        {
            cpu_score++;
            ResetBall();
            // cout << "cpu: " << cpu_score << endl;
        }
    }

    void ResetBall()
    {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int dir[] = {1, -1};
        speed_x *= dir[GetRandomValue(0, 1)];
        speed_y *= dir[GetRandomValue(0, 1)];
    }
};

class Paddle
{
protected:
    void LimitMovement()
    {
        if (y <= 0) // stop moving beyound the screen hight
        {
            y = 0;
        }
        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;
    float width, height;
    int speed = 8;

    void Draw()
    {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 1, 0, WHITE);
    }
    void Update()
    {
        if (IsKeyDown(KEY_UP)) // Move up
        {
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) // Move down
        {
            y += speed;
        }
        LimitMovement();
    }
};

class CpuPaddle : public Paddle
{
public:
    void Update(int boll_y)
    {
        // Track the y movement of ball
        if ((y + height / 2) > boll_y)
        {
            y -= speed;
        }
        if ((y + height / 2) <= boll_y)
        {
            y += speed;
        }
        LimitMovement();
    }
};

// Creating the Ball , Paddle(player) and CpuPaddle Object
Ball ball;
Paddle player;
CpuPaddle cpu;

int main()
{
    const int ScreenWidth = 1280;
    const int ScreenHight = 720;

    cout << "Game is Started" << endl;

    // To make window we have use InitWindow(w,h,title)
    InitWindow(ScreenWidth, ScreenHight, "Pong Game");

    // Set MaxFPS of the Game
    SetTargetFPS(60);

    // Set the values of Ball
    ball.x = ScreenWidth / 2;
    ball.y = ScreenHight / 2;
    ball.radius = 20;

    // Set the values of Paddle(player)
    player.width = 25;
    player.height = 120;
    player.x = 10;
    player.y = (ScreenHight / 2) - (player.height / 2);

    // Set the values of CpuPaddle
    cpu.width = 25;
    cpu.height = 120;
    cpu.x = ScreenWidth - 35;
    cpu.y = (ScreenHight / 2) - (cpu.height / 2);

    while (WindowShouldClose() == false) // WindowShouldClose is use to check esc key or close button is pressed
    {
        BeginDrawing(); // Start Drawing

        /* Update */
        ball.Update();      // update the balls position
        player.Update();    // update the player position
        cpu.Update(ball.y); // update the cpu position

        /* Checking the collision */
        // check collision between ball and player
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x *= -1;
        }
        // check collision between ball and cpu
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x *= -1;
        }

        /* Drawing object section */
        ClearBackground(Red_light); // Clearing the background to fix multiple objects displaying
        DrawCircle(ScreenWidth / 2, ScreenHight / 2, 220, Red_dark);
        DrawText(TextFormat("%d", player_score), ScreenWidth / 4, 30, 50, WHITE);
        DrawText(TextFormat("%d", cpu_score), 3 * ScreenWidth / 4, 30, 50, WHITE);
        DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHight, WHITE);
        ball.Draw();   // drawing the ball
        player.Draw(); // draw the player
        cpu.Draw();    // draw the cpu

        EndDrawing(); // End Drawing
    }

    // It is important to close window
    CloseWindow();

    return 0;
}