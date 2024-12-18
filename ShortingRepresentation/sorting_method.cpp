#include "sorting_method.h"

SortBase::SortBase()
{
    i = 0;
    j = 0;
    size = 128;
    sort = false;

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % GetScreenHeight();
    }
}

void SortBase::DrawArray(int k = -1)
{
    for (int i = 0; i < size; i++)
    {
        if (i == k || sort == true)
        {
            DrawRectangle(i * 10, GetScreenHeight() - arr[i], 10 - 1, arr[i], GREEN);
        }
        else
        {
            DrawRectangle(i * 10, GetScreenHeight() - arr[i], 10 - 1, arr[i], WHITE);
        }
    }
}

void BubbleSort::Draw()
{
    if (!sort)
    {
        StepSort();
        DrawArray(j);
    }
    else
    {
        DrawArray();
    }
}

void BubbleSort::StepSort()
{
    if (i < size - 1)
    {
        if (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
    }
    else
    {
        sort = true;
    }
}

SelectionSort::SelectionSort()
{
    min = 0;
}

void SelectionSort::Draw()
{
    if (!sort)
    {
        StepSort();
        DrawArray(min);
    }
    else
    {
        DrawArray();
    }
}

void SelectionSort::StepSort()
{
    if (i < size - 1)
    {
        if (j == i)
        {
            min = i;
        }
        if (j < size)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            j++;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

            j = i + 1;
            i++;
        }
    }
    else
    {
        sort = true;
    }
}

InsertionSort::InsertionSort()
{
    i = 1;
}

void InsertionSort::Draw()
{
    if (!sort)
    {
        StepSort();
        DrawArray(j);
    }
    else
    {
        DrawArray();
    }
}

void InsertionSort::StepSort()
{
    if (i < size)
    {
        if (j >= 0 && arr[j] > arr[j + 1])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
        else
        {
            i++;
            j = i - 1;
        }
    }
    else
    {
        sort = true;
    }
}
