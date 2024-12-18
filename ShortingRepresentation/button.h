#pragma once
#include <raylib.h>

class Button
{
private:
    Vector2 position;

    char text[20];
    int textsize;
    int fontsize;

    Rectangle rec;
    float width, hight;
    Color color_normal;
    Color color_hover;

public:
    Button(Vector2 pos, char *str, Color color);
    void Draw();
    bool IsPressed();
    bool IsHover();
};
