#pragma once
#include <raylib.h>
#include <iostream>

class Button
{
private:
    Vector2 position;
    std::string text;

    int textsize;
    int fontsize;

    Rectangle rec;
    float width, hight;
    Color color_normal;
    Color color_hover;

    void Resize();

public:
    Button(Vector2 pos, std::string str, Color color);

    void Draw();
    void SetText(std::string new_text);
    std::string GetText();
    bool IsPressed();
    bool IsHover();
};
