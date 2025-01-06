#pragma once
#include <raylib.h>

class Pipe
{
private:
    Vector2 position;

    Texture2D pipe_texture;

    int speed;

public:
    Pipe() {}
    Pipe(Vector2 position, int speed, bool flip);
    ~Pipe();

    Rectangle pipe_hitbox;
    bool flip;

    void Draw();
    void Update();
    bool IsOffScreen();
};
