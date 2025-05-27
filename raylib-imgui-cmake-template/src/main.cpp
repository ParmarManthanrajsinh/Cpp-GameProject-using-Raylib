#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

int main() {
    // Initialization
    InitWindow(800, 600, "rlImGui Example");
    SetTargetFPS(60);

    // Initialize rlImGui
    rlImGuiSetup(true); // true = auto load fonts

    // Main game loop
    while (!WindowShouldClose()) {
        // Start Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

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
