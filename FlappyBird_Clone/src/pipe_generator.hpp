#pragma once

#include "pipe.hpp"

using namespace std;

class PipeGenerator
{
private:
    Pipe *pipe1;
    Pipe *pipe2;
    Pipe *pipe3;
    Pipe *pipe4;
    Pipe *pipe5;

    int pipe_speed;

    double lastUpdateTime;
    bool Delay(double intervel);

    Sound hit_sound;
    Sound die_sound;

public:
    int pipe_spawn_counter;
    
    PipeGenerator();
    ~PipeGenerator();


    void Draw();
    void Update();
    void Reset();
    bool CheckCollision(Rectangle bird);
};