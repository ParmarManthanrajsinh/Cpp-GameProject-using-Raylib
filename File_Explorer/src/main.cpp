#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_name");
    GuiLoadStyle("styles/style_genesis.rgs");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    Vector2 anchor01 = {0, 0};
    Vector2 anchor02 = {0, 0};

    bool WindowBox000Active = true;
    Rectangle ScrollPanel002ScrollView = {0, 0, 0, 0};
    Vector2 ScrollPanel002ScrollOffset = {0, 0};
    Vector2 ScrollPanel002BoundsOffset = {0, 0};
    bool Toggle003Active = true;
    bool Toggle004Active = true;
    bool Toggle005Active = true;
    bool Toggle006Active = true;

    Rectangle layoutRecs[7] = {
        (Rectangle){anchor01.x + 0, anchor01.y + 0, 1280, 720},
        (Rectangle){anchor02.x + 8, anchor02.y + 32, 144, 680},
        (Rectangle){anchor01.x + 160, anchor01.y + 32, 1112, 680},
        (Rectangle){anchor02.x + 16, anchor02.y + 80, 128, 24},
        (Rectangle){anchor02.x + 16, anchor02.y + 112, 128, 24},
        (Rectangle){anchor02.x + 16, anchor02.y + 144, 128, 24},
        (Rectangle){anchor02.x + 16, anchor02.y + 48, 128, 24},
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (WindowBox000Active)
        {
            WindowBox000Active = !GuiWindowBox(layoutRecs[0], "MyFile Explorer");
            GuiScrollPanel((Rectangle){layoutRecs[2].x, layoutRecs[2].y, layoutRecs[2].width - ScrollPanel002BoundsOffset.x, layoutRecs[2].height - ScrollPanel002BoundsOffset.y}, NULL, layoutRecs[2], &ScrollPanel002ScrollOffset, &ScrollPanel002ScrollView);
        }
        GuiGroupBox(layoutRecs[1], "files");
        GuiToggle(layoutRecs[3], "file1", &Toggle003Active);
        GuiToggle(layoutRecs[4], "file2", &Toggle004Active);
        GuiToggle(layoutRecs[5], "file3", &Toggle005Active);
        GuiToggle(layoutRecs[6], "..", &Toggle006Active);
        //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
