#pragma once

#include <raylib.h>
#include <vector>
#include <iostream>
using namespace std;

class Sprite
{
private:
    Vector2 position;
    vector<Texture2D> sprites;

    int total_no_frames;
    int current_frame;

    double animation_speed;

public:
    bool IsAnimation;
    bool loop;
    bool hflip;

    float scale;
    float rotation;

    Sprite(Vector2 pos, vector<Image> images, double animationSpeed, bool looping);
    ~Sprite();

    void Draw();

    void SetPosition(Vector2 newPosition) { position = newPosition; }
    const Vector2 GetPosition() { return position; }
};
