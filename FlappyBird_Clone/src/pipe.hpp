#pragma once
#include <raylib.h>

class Pipe
{
private:
    Rectangle pipe_hitbox;
    Vector2 position;

    Texture2D pipe_texture;

    int speed;
public:
    Pipe(Vector2 position, int speed, bool flip);
    ~Pipe();

    bool flip;

    void Draw();
    void Update();
    bool IsOffScreen();
};
