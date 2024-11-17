#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <deque>

using namespace std;

Color green = {69, 222, 27, 255};

int cellsize = 30;
int cellcount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool Delay(double intervel)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= intervel)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{offset + x * cellsize, offset + y * cellsize, (float)cellsize, (float)cellsize};
            DrawRectangleRounded(segment, 0.5, 2, green);
        }
    }

    void Update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], direction));
    }

    void Reset()
    {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        direction = {1, 0};
    }
};

class Food
{

public:
    Vector2 position;
    Texture2D texture;

    Food(deque<Vector2> snakebody)
    {
        // Load image
        Image apple_img = LoadImage("asset/apple.png");
        // Convert image to texture
        texture = LoadTextureFromImage(apple_img);
        // Unloading the image to save memory
        UnloadImage(apple_img);

        // Set Random position for food
        position = GetRandowPosition(snakebody);
    }

    ~Food()
    {
        // Unloading the texture to save memory
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, offset + position.x * cellsize, offset + position.y * cellsize, WHITE);
        // DrawRectangle(position.x * cellsize, position.y * cellsize, cellsize, cellsize, green);
    }

    Vector2 GetRandowPosition(deque<Vector2> snakebody)
    {
        float x = GetRandomValue(0, cellcount - 1);
        float y = GetRandomValue(0, cellcount - 1);
        Vector2 pos = {x, y};

        for (unsigned int i = 0; i < snakebody.size(); i++)
        {
            if (Vector2Equals(snakebody[i], pos))
            {
                pos = GetRandowPosition(snakebody);
            }
        }

        return pos;
    }
};

class Game
{
public:
    Snake snake;
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eatsound;
    Sound wallsound;

    Game()
    {
        InitAudioDevice();
        eatsound = LoadSound("asset/eat_sound.wav");
        wallsound = LoadSound("asset/wall_sound.wav");
    }

    ~Game()
    {
        UnloadSound(eatsound);
        UnloadSound(wallsound);
        CloseAudioDevice();
    }

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update()
    {
        if (running)
        {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void CheckCollisionWithFood()
    {
        if (Vector2Equals(snake.body[0], food.position))
        {
            snake.body.push_front(Vector2Add(snake.body[0], snake.direction));
            food.position = food.GetRandowPosition(snake.body);
            score++;
            PlaySound(eatsound);
        }
    }

    void CheckCollisionWithEdges()
    {
        if (snake.body[0].x == cellcount || snake.body[0].x == -1)
        {
            GameOver();
        }
        if (snake.body[0].y == cellcount || snake.body[0].y == -1)
        {
            GameOver();
        }
    }

    void CheckCollisionWithTail()
    {
        // deque<Vector2> headlessBody = snake.body;
        // headlessBody.pop_front();

        for (unsigned int i = 1; i < snake.body.size(); i++)
        {
            if (Vector2Equals(snake.body[i], snake.body[0]))
            {
                GameOver();
            }
        }
    }

    void GameOver()
    {
        PlaySound(wallsound);
        snake.Reset();
        food.position = food.GetRandowPosition(snake.body);
        running = false;
        score = 0;
    }
};

int main()
{
    InitWindow(2 * offset + cellsize * cellcount, 2 * offset + cellsize * cellcount, "SnakeGame");
    SetTargetFPS(60);

    Game game;

    // Game Loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        ClearBackground(BLACK);

        if (Delay(0.2))
        {
            game.Update();
        }
        /* Keyboard input */
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
        {
            game.snake.direction = {0, -1};
            game.running = true;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
        {
            game.snake.direction = {0, 1};
            game.running = true;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
        {
            game.snake.direction = {-1, 0};
            game.running = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
        {
            game.snake.direction = {1, 0};
            game.running = true;
        }

        game.Draw();

        // // Drawing the Grid
        // for (int i = 0; i < cellcount; i++)
        // {
        //     DrawLine(offset + i * cellsize, 0, offset + i * cellsize, offset + cellsize * cellsize, WHITE);
        //     DrawLine(0, offset + i * cellsize, offset + cellsize * cellsize, offset + i * cellsize, WHITE);
        // }
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellsize * cellcount + 10, (float)cellsize * cellcount + 10}, 5, WHITE);
        DrawText(TextFormat("Score: %d", game.score), offset - 5, 20, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}