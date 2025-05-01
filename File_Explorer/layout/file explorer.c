/*******************************************************************************************
*
*   File explorer v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void Button003();
static void Button004();
static void Button005();
static void Button006();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "file explorer");

    // file explorer: controls initialization
    //----------------------------------------------------------------------------------
    Vector2 anchor01 = { 0, 0 };
    Vector2 anchor02 = { 0, 0 };
    
    bool WindowBox000Active = true;
    Rectangle ScrollPanel002ScrollView = { 0, 0, 0, 0 };
    Vector2 ScrollPanel002ScrollOffset = { 0, 0 };
    Vector2 ScrollPanel002BoundsOffset = { 0, 0 };

    Rectangle layoutRecs[7] = {
        (Rectangle){ anchor01.x + 0, anchor01.y + 0, 1280, 720 },
        (Rectangle){ anchor02.x + 8, anchor02.y + 32, 144, 680 },
        (Rectangle){ anchor01.x + 160, anchor01.y + 32, 1112, 680 },
        (Rectangle){ anchor02.x + 16, anchor02.y + 48, 128, 24 },
        (Rectangle){ anchor02.x + 16, anchor02.y + 80, 128, 24 },
        (Rectangle){ anchor02.x + 16, anchor02.y + 112, 128, 24 },
        (Rectangle){ anchor02.x + 16, anchor02.y + 144, 128, 24 },
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
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
                GuiScrollPanel((Rectangle){layoutRecs[2].x, layoutRecs[2].y, layoutRecs[2].width - ScrollPanel002BoundsOffset.x, layoutRecs[2].height - ScrollPanel002BoundsOffset.y }, NULL, layoutRecs[2], &ScrollPanel002ScrollOffset, &ScrollPanel002ScrollView);
            }
            GuiGroupBox(layoutRecs[1], "files");
            if (GuiButton(layoutRecs[3], "..")) Button003(); 
            if (GuiButton(layoutRecs[4], "file1")) Button004(); 
            if (GuiButton(layoutRecs[5], "file2")) Button005(); 
            if (GuiButton(layoutRecs[6], "file3")) Button006(); 
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void Button003()
{
    // TODO: Implement control logic
}
static void Button004()
{
    // TODO: Implement control logic
}
static void Button005()
{
    // TODO: Implement control logic
}
static void Button006()
{
    // TODO: Implement control logic
}

