#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>
#include <vector>
#include "sprite.hpp"

vector<Image> CreateImages()
{
    vector<Image> images;

    Image img1 = LoadImage("Sprites/Idle/idle1.png");
    images.push_back(img1);
    Image img2 = LoadImage("Sprites/Idle/idle2.png");
    images.push_back(img2);
    Image img3 = LoadImage("Sprites/Idle/idle3.png");
    images.push_back(img3);
    Image img4 = LoadImage("Sprites/Idle/idle4.png");
    images.push_back(img4);

    return images;
}

int main()
{
    InitWindow(1280, 720, "Raygui Example");
    SetTargetFPS(60);

    bool toggleButton = true;
    float rotate = 0.0f;
    float scale = 1.0f;
    int dropdownBox = 0;
    bool dropdownBoxActive = false;
    bool checkBox = false;
    bool drawCharacter = false;

    Sprite sprite({500, 350}, CreateImages(), 0.2, true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw GUI controls
        if (GuiButton((Rectangle){50, 50, 200, 30}, "Draw Character"))
        {
            drawCharacter = !drawCharacter;
        }

        GuiCheckBox((Rectangle){50, 100, 20, 20}, "Hfilp", &checkBox);
        sprite.hflip = checkBox;

        GuiSlider((Rectangle){50, 150, 200, 20}, "Rotate", TextFormat("%.0f", rotate), &rotate, 0, 360);
        sprite.rotation = rotate;

        GuiSlider((Rectangle){50, 180, 200, 20}, "Scale", TextFormat("%.2f", scale), &scale, 0.1f, 5.0f);
        sprite.scale = scale;

        GuiToggle((Rectangle){50, 220, 120, 30}, "Stop Animation", &toggleButton);
        sprite.IsAnimation = toggleButton;

        if (GuiDropdownBox((Rectangle){50, 270, 120, 30}, "Option 1;Option 2;Option 3", &dropdownBox, dropdownBoxActive))
        {
            dropdownBoxActive = !dropdownBoxActive;
        }

        if (drawCharacter) sprite.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}