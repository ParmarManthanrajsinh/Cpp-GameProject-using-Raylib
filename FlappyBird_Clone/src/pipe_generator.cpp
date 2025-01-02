#include "pipe_generator.hpp"

bool PipeGenerator::Delay(double intervel)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= intervel)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

PipeGenerator::PipeGenerator()
    : pipe_speed(1), pipe_spawn_counter(0), lastUpdateTime(0) {}

PipeGenerator::~PipeGenerator()
{
    pipes.clear();
}

void PipeGenerator::Draw()
{
    for (auto it = pipes.begin(); it != pipes.end(); it++)
    {
        it->Draw();
    }
}

void PipeGenerator::Update()
{
    if (Delay(2))
    {
        int random_int = GetRandomValue(0, 1);
        float y = (random_int == 0) ? 0 : (GetScreenHeight() - 320);

        pipes.push_back(Pipe({288, y}, pipe_speed, (random_int == 0)));
        pipe_spawn_counter++;
    }

    for (auto it = pipes.begin(); it != pipes.end();)
    {
        it->Update();

        // Remove off-screen pipes
        if (it->IsOffScreen())
        {
            it = pipes.erase(it);
        }
        else{
            it++;
        }
    }
}
