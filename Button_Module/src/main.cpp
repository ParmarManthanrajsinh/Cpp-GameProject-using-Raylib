/* Example Code for Use of My Modules*/

// Create Button With simple Syntax
// Also has Hover Effect

// Create Sprite With simple Syntax
// Include various inbuild features like scale, rotation, looping

// Just need to Include the header file and you are good to go

#include <raylib.h>
#include "button.hpp"
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
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    Color BGcolor = BLACK;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Example of Modules");
    SetTargetFPS(60);

    // Button(Vector2, text, ButtonColor, TextColor)
    Button button({10, 10}, "Pause", RED, BLACK);
    Button reset({10, 60}, "Reset", WHITE, BLACK);

    // Change the Button Color
    button.SetColor(BLUE);
    // Change the Button padding left
    button.SetLeftPadding(100); // Note Default is 50

    // Sprite(Vector2, vector<Image>, float_scale, animation_speed, looping)
    Sprite sprite({10, 400}, CreateImages(), 0.2, true); // animation speed optimal 0.2

    // Control rotation and scale
    sprite.rotation = 0;
    sprite.scale = 2;

    while (!WindowShouldClose())
    {
        // Check if the Button is Pressed
        if (button.IsPressed())
        {
            BGcolor = RED;
            // Pause Animation
            sprite.IsAnimation = false;
        }
        if (reset.IsPressed())
        {
            BGcolor = BLACK;
            // Play Animation
            sprite.IsAnimation = true;
        }

        // Check if the Button is Hover
        // if (button.IsHover())
        // {
        //      // code
        // }

        BeginDrawing();

        ClearBackground(BGcolor);

        // Draw Button
        button.Draw();
        reset.Draw();

        // Draw Sprite
        sprite.Draw();

        EndDrawing();
    }

    CloseWindow();
}