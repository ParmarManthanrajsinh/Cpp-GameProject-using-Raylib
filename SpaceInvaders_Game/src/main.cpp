#include <raylib.h>
#include <string>
#include "game.hpp"

std::string FormatWithLeadingZeros(int number, int width)
{
    std::string score = std::to_string(number);
    int zeros = width - score.length();
    return std::string(zeros, '0') + score;
}

int main()
{
    const int screenWidth = 750;
    const int screenHeight = 700;
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};

    int offset = 50;

    InitWindow(screenWidth + offset, screenHeight + 2 * offset, "Space Invaders");

    // Importent to laod the font before the InitWindow
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D image = LoadTexture("Graphics/spaceship.png");
    InitAudioDevice();

    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();

        BeginDrawing();

        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18, 20, 2, yellow);

        DrawLineEx({25, 730}, {775, 730}, 3, yellow);
        if (game.run)
        {
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);
        }
        else
        {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);
        }

        for (int i = 0; i < game.lives; i++)
        {
            DrawTextureV(image, {float(50 + i * 50), 745}, WHITE);
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string score = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, score.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, yellow);
        std::string highscore = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscore.c_str(), {655, 40}, 34, 2, yellow);

        game.Draw();

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
}