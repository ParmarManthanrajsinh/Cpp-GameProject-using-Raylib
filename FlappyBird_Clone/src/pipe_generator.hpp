#pragma once

#include <vector>
#include "pipe.hpp"

using namespace std;

class PipeGenerator
{
private:
    vector<Pipe> pipes;
    int pipe_speed;
    int pipe_spawn_counter;

    double lastUpdateTime;
    bool Delay(double intervel);

public:
    PipeGenerator();
    ~PipeGenerator();
    void Draw();
    void Update();
};