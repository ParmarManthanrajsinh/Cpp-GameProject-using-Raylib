#include "button.hpp"
#include <math.h>
#include <iostream>

void Button::Resize()
{
    textsize = MeasureText(text.c_str(), fontsize);
    width = textsize + 50;
    hight = fontsize * 2;
    rec = {position.x, position.y, width, hight};
}

Button::Button(Vector2 pos, std::string str, Color color)
{
    position = pos;
    text = str;
    fontsize = 20;

    Resize();

    color_normal = color;

    unsigned char r = std::max(color.r - 10, 0);
    unsigned char g = std::max(color.g - 10, 0);
    unsigned char b = std::max(color.b - 10, 0);
    color_hover = {r, g, b, 255};
}

void Button::Draw()
{
    if (IsHover())
    {
        DrawRectangleRounded(rec, 0.4, 1, color_hover);
    }
    else
    {
        DrawRectangleRounded(rec, 0.4, 1, color_normal);
    }

    DrawText(text.c_str(), position.x + 25, position.y + (hight - fontsize) / 2, fontsize, WHITE);
}

void Button::SetText(std::string new_text)
{
    text = new_text;
    Resize();
}

bool Button::IsPressed()
{
    Vector2 mouse_pos = GetMousePosition();
    bool mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    if (CheckCollisionPointRec(mouse_pos, rec) && mouse_pressed)
    {
        return true;
    }
    return false;
}

bool Button::IsHover()
{
    Vector2 mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, rec))
    {
        return true;
    }
    return false;
}
