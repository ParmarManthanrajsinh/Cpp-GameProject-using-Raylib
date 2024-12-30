#include "flappybird.hpp"

FlappyBird::FlappyBird(Vector2 pos)
{
    position = pos;
    bird = new Sprite(position, vector<Image>{LoadImage("GameObjects/yellowbird-downflap.png"), LoadImage("GameObjects/yellowbird-midflap.png"), LoadImage("GameObjects/yellowbird-upflap.png")}, 0.2, true);
    bird->scale = 1.5;
}

FlappyBird::~FlappyBird()
{
    delete bird;
}

void FlappyBird::Draw()
{
    bird->Draw();
}
