#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

int main()
{
    // Initialize window
    InitWindow(800, 450, "Raygui Example");
    SetTargetFPS(60);

    // Variables for GUI controls
    bool toggleButton = false;
    float sliderValue = 50.0f;
    int dropdownBox = 0;
    bool dropdownBoxActive = false;
    bool checkBox = false;

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw GUI controls
        if (GuiButton((Rectangle){50, 50, 200, 30}, "Click Me!"))
        {
            // Action when button is pressed
        }

        GuiCheckBox((Rectangle){50, 100, 20, 20}, "Check Box", &checkBox);

        GuiSlider((Rectangle){50, 150, 200, 20}, "Slider", TextFormat("%.0f", sliderValue), &sliderValue, 0, 100);

        GuiToggle((Rectangle){50, 200, 120, 30}, "Toggle Button", &toggleButton);

        if (GuiDropdownBox((Rectangle){50, 250, 120, 30}, "Option 1;Option 2;Option 3", &dropdownBox, dropdownBoxActive))
        {
            dropdownBoxActive = !dropdownBoxActive;
        }

        DrawText("Raygui Controls Example", 300, 50, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}