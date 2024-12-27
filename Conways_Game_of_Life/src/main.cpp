#include <raylib.h>
#include "simulation.hpp"
#include "button.hpp"

int main()
{
    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;
    const int cell_size = 25;

    Color grey = {29, 29, 29, 255};
    int FPS = 12;

    InitWindow(SCREEN_WIDTH + 220, SCREEN_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT, cell_size);
    Button PlayButton({SCREEN_WIDTH + 40, 40}, "Play", BLUE);
    Button RandomButton({SCREEN_WIDTH + 40, 120}, "Randomize", BLUE);
    Button ClearButton({SCREEN_WIDTH + 40, 180}, "Clear", BLUE);
    Button SpeedDownButton({SCREEN_WIDTH + 40, 260}, "<<", BLUE);
    Button SpeedUpButton({SCREEN_WIDTH + 120, 260}, ">>", BLUE);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 position = GetMousePosition();
            int row = position.y / cell_size;
            int col = position.x / cell_size;
            simulation.ToggleCell(row, col);
        }

        if (PlayButton.IsPressed())
        {
            if (!simulation.IsRunning())
            {
                simulation.Start();
                SetWindowTitle("Game of Life is running");
                PlayButton.SetText("Pause");
            }
            else
            {
                simulation.Stop();
                SetWindowTitle("Game of Life is stopped");
                PlayButton.SetText("Play");
            }
        }
        else if (SpeedUpButton.IsPressed())
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (SpeedDownButton.IsPressed())
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (RandomButton.IsPressed())
        {
            simulation.Stop();
            simulation.CreateRandomState();
            SetWindowTitle("Game of Life is stopped");
            PlayButton.SetText("Play");
        }
        else if (ClearButton.IsPressed())
        {
            simulation.Stop();
            simulation.ClearGrid();
            SetWindowTitle("Game of Life is stopped");
            PlayButton.SetText("Play");
        }

        simulation.Update();

        BeginDrawing();

        ClearBackground(grey);
        simulation.Draw();
        PlayButton.Draw();
        RandomButton.Draw();
        ClearButton.Draw();
        SpeedUpButton.Draw();
        SpeedDownButton.Draw();

        EndDrawing();
    }

    CloseWindow();
}