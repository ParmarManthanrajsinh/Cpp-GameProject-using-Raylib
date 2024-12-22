#pragma once
#include <raylib.h>

class Alien
{
private:
public:
    static Texture2D alienimages[3];
    Vector2 position;
    int type;

    Alien(int type, Vector2 pos);
    void Draw();
    void Update(int direction);
    int GetType();
    Rectangle GetRect();

    static void UnloadAlienImages();
    
};
