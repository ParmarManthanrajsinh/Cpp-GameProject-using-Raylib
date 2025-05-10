#include "pipe_generator.hpp"
#include <iostream>

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
{
    pipe1 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe2 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe3 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe4 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe5 = new Pipe({-1000, -1000}, pipe_speed, false);

    hit_sound = LoadSound("SoundEfects/hit.wav");
    die_sound = LoadSound("SoundEfects/die.wav");

    pipe_spawn_counter = 0;
    pipe_speed = 1;
    lastUpdateTime = 0;
}

// Pipe distroyer 😁😁
PipeGenerator::~PipeGenerator()
{
    delete pipe1;
    delete pipe2;
    delete pipe3;
    delete pipe4;
    delete pipe5;

    UnloadSound(hit_sound);
    UnloadSound(die_sound);
}

void PipeGenerator::Draw()
{
    pipe1->Draw();
    pipe2->Draw();
    pipe3->Draw();
    pipe4->Draw();
    pipe5->Draw();
}

void PipeGenerator::Update()
{
    if (pipe_spawn_counter > 20)
    {
        pipe_speed = 2;
    }
    else if (pipe_spawn_counter > 50)
    {
        pipe_speed = 3;
    }

    if (Delay(GetRandomValue(3, 4)))
    {
        if (pipe1->IsOffScreen())
        {
            int random_int = GetRandomValue(0, 1);
            float y = (random_int == 0) ? GetRandomValue(-100, 0) : (GetScreenHeight() - GetRandomValue(100, 320));

            pipe1 = new Pipe({288, y}, pipe_speed, (random_int == 0));
            pipe_spawn_counter++;
        }
        else if (pipe2->IsOffScreen())
        {
            int random_int = GetRandomValue(0, 1);
            float y = (random_int == 0) ? GetRandomValue(-100, 0) : (GetScreenHeight() - GetRandomValue(100, 320));

            pipe2 = new Pipe({288, y}, pipe_speed, (random_int == 0));
            pipe_spawn_counter++;
        }
        else if (pipe3->IsOffScreen())
        {
            int random_int = GetRandomValue(0, 1);
            float y = (random_int == 0) ? GetRandomValue(-100, 0) : (GetScreenHeight() - GetRandomValue(100, 320));

            pipe3 = new Pipe({288, y}, pipe_speed, (random_int == 0));
            pipe_spawn_counter++;
        }
        else if (pipe4->IsOffScreen())
        {
            int random_int = GetRandomValue(0, 1);
            float y = (random_int == 0) ? GetRandomValue(-100, 0) : (GetScreenHeight() - GetRandomValue(100, 320));

            pipe4 = new Pipe({288, y}, pipe_speed, (random_int == 0));
            pipe_spawn_counter++;
        }
        else if (pipe5->IsOffScreen())
        {
            int random_int = GetRandomValue(0, 1);
            float y = (random_int == 0) ? GetRandomValue(-100, 0) : (GetScreenHeight() - GetRandomValue(100, 320));

            pipe5 = new Pipe({288, y}, pipe_speed, (random_int == 0));
            pipe_spawn_counter++;
        }
    }
    pipe1->Update();
    pipe2->Update();
    pipe3->Update();
    pipe4->Update();
    pipe5->Update();
}

void PipeGenerator::Reset()
{
    pipe_spawn_counter = 0;
    pipe_speed = 1;
    lastUpdateTime = 0;

    pipe1 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe2 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe3 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe4 = new Pipe({-1000, -1000}, pipe_speed, false);
    pipe5 = new Pipe({-1000, -1000}, pipe_speed, false);
}

bool PipeGenerator::CheckCollision(Rectangle bird)
{
    if (CheckCollisionRecs(bird, pipe1->pipe_hitbox))
    {
        PlaySound(hit_sound);
        PlaySound(die_sound);
        return true;
    }
    if (CheckCollisionRecs(bird, pipe2->pipe_hitbox))
    {
        PlaySound(hit_sound);
        PlaySound(die_sound);
        return true;
    }
    if (CheckCollisionRecs(bird, pipe3->pipe_hitbox))
    {
        PlaySound(hit_sound);
        PlaySound(die_sound);
        return true;
    }
    if (CheckCollisionRecs(bird, pipe4->pipe_hitbox))
    {
        PlaySound(hit_sound);
        PlaySound(die_sound);
        return true;
    }
    if (CheckCollisionRecs(bird, pipe5->pipe_hitbox))
    {
        PlaySound(hit_sound);
        PlaySound(die_sound);
        return true;
    }
    return false;
}