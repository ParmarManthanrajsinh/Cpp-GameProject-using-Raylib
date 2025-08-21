#include <raylib.h>
#include <rlImGui.h>
#include <imgui.h>

#include "background.hpp"

int main() {
    // Initialization
    InitWindow(900, 900, "rlImGui Example");
    SetTargetFPS(60);

    // Initialize rlImGui
    rlImGuiSetup(true); // true = auto load fonts

    Background background("../assets/oggy.jpeg"); // Load a background image

    // Main game loop
    while (!WindowShouldClose()) {
        // Start Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the background
        background.Draw();

        // Start ImGui frame
        rlImGuiBegin();

        // Your ImGui Code
        ImGui::Begin("Demo Window");
        ImGui::Text("Hello, world!");
        static int counter = 0;
        if (ImGui::Button("Click Me")) {
            counter++;
        }
        ImGui::Text("Button pressed %d times", counter);
        ImGui::End();

        // End ImGui Frame
        rlImGuiEnd();

        EndDrawing();
    }

    // Cleanup
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
