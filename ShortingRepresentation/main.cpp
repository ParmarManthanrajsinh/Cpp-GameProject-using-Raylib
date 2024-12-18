#include "sorting_method.h"
#include "button.h"
#include <chrono>

using namespace std;

enum SortMethod
{
    NONE,
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    QUICK_SORT
};

int main()
{
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_WIDTH = 1280;
    char time[30];

    char text_bubble_sort[20] = "Bubble Sort";
    char text_selection_sort[20] = "Selection Sort";
    char text_insertion_sort[20] = "Insertion Sort";
    char text_back[20] = "Back";

    SortMethod currentSortMethod = NONE;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sorting Visualization");
    SetTargetFPS(120);

    Button button_bubblesort(Vector2{20, 20}, text_bubble_sort, BLUE);
    Button button_selectionsort(Vector2{20, 100}, text_selection_sort, BLUE);
    Button button_insertionsort(Vector2{20, 180}, text_insertion_sort, BLUE);
    Button button_back(Vector2{SCREEN_WIDTH - 150, SCREEN_HEIGHT - 80}, text_back, BLUE);
    SortBase *sort;

    auto start_time = chrono::high_resolution_clock::now();
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (currentSortMethod == NONE)
        {
            button_bubblesort.Draw();
            button_selectionsort.Draw();
            button_insertionsort.Draw();

            if (button_bubblesort.IsPressed())
            {
                currentSortMethod = BUBBLE_SORT;
                start_time = chrono::high_resolution_clock::now();
                sort = new BubbleSort;
            }
            else if (button_selectionsort.IsPressed())
            {
                currentSortMethod = SELECTION_SORT;
                start_time = chrono::high_resolution_clock::now();
                sort = new SelectionSort;
            }
            else if (button_insertionsort.IsPressed())
            {
                currentSortMethod = INSERTION_SORT;
                start_time = chrono::high_resolution_clock::now();
                sort = new InsertionSort;
            }
        }
        else
        {
            sort->Draw();
            button_back.Draw();

            if (button_back.IsPressed())
            {
                currentSortMethod = NONE;
            }

            if (sort->sort == true)
            {
                DrawText(time, 600, 60, 30, RED);
            }
            else
            {
                end_time = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
                snprintf(time, sizeof(time), "%lld s", duration.count());

                DrawText(time, 600, 60, 30, RED);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
