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
    int padding_left;

    Rectangle rec;
    float width, hight;
    Color color_normal;
    Color color_hover;
    Color color_text;

    void Resize();

public:
    Button(Vector2 pos, std::string str, Color colornormal, Color colortext);

    void Draw();

    bool IsPressed();
    bool IsHover();

    void SetText(std::string new_text);
    std::string GetText();

    // Set Color_normal and Color_pressed
    void SetColor(Color color);
    // Set Color_normal
    void SetColorNormal(Color color);
    // Set Color_pressend
    void SetColorPressed(Color color);

    // Set Left Padding
    void SetLeftPadding(int n);
};
