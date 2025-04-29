#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>
#include <vector>
#include "sprite.hpp"

vector<Image> CreateImages()
{
    vector<Image> images;

    images.push_back(LoadImage("Sprites/Idle/idle1.png"));
    images.push_back(LoadImage("Sprites/Idle/idle2.png"));
    images.push_back(LoadImage("Sprites/Idle/idle3.png"));
    images.push_back(LoadImage("Sprites/Idle/idle4.png"));

    return images;
}

int main()
{
    InitWindow(1280, 720, "Raygui Example");
    SetTargetFPS(60);

    bool toggleButton = true;
    float rotate = 0.0f;
    float scale = 1.0f;
    int dropdownIndex = 0;
    int previousDropdownIndex = -1;
    bool dropdownBoxActive = false;
    bool checkBox = false;
    bool drawCharacter = false;

    string styles[] = {
        "amber",
        "ashes",
        "bluish",
        "candy",
        "cherry",
        "cyber",
        "dark",
        "enefete",
        "genesis",
        "jungle",
        "lavanda",
        "rltech",
        "sunny",
        "terminal"};

    Sprite sprite({500, 350}, CreateImages(), 0.2, true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

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

        if (GuiDropdownBox((Rectangle){950, 50, 200, 30}, "amber; ashes; bluish; candy; cherry; cyber; dark; enefete; genesis; jungle; lavanda; rltech; sunny; terminal", &dropdownIndex, dropdownBoxActive))
        {
            dropdownBoxActive = !dropdownBoxActive;
        }

        if (dropdownIndex != previousDropdownIndex)
        {
            GuiLoadStyle(TextFormat("styles/style_%s.rgs", styles[dropdownIndex].c_str()));
            previousDropdownIndex = dropdownIndex;
        }

        if (drawCharacter)
            sprite.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}