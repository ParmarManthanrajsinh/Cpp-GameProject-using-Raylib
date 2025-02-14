#pragma once

#include <iostream>
#include <raylib.h>

class SortBase
{
protected:
    int i, j;
    int arr[128];
    int size;

    void DrawArray(int k);
    virtual void StepSort() = 0;

public:
    bool sort;

    SortBase();
    virtual void Draw() = 0;
};

class BubbleSort : public SortBase
{
private:
    void StepSort();

public:
    void Draw();
};

class SelectionSort : public SortBase
{
private:
    int min;

    void StepSort();

public:
    SelectionSort();
    void Draw();
};

class InsertionSort : public SortBase
{
private:
    void StepSort();

public:
    InsertionSort();
    void Draw();
};
