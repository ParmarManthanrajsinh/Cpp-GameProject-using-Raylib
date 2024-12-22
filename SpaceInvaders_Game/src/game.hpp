#pragma once

#include "spaceship.hpp"
#include "obstacle.hpp"
#include "alien.hpp"
#include "mysteryship.hpp"

class Game
{
private:
    SpaceShip spaceship;
    MysteryShip mysteryship;

    void DeleteInactiveLaser();
    void MoveAliens();
    void MoveDownAliens(int distance);
    void AlienShootLaser();
    void CheckCollision();
    void Reset();
    void InitGame();    
    void GameOver();
    void CheckForHighScore();
    void SaveHighScore();
    void LoadHighScore();

    int direction;
    constexpr static float alienlasershootinterval = 0.35;
    float timelastalienfired;
    float mysteryshipspawninterval = 0.35;
    float timelastspawn;

    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    std::vector<Laser> alienslasers;

    std::vector<Obstacle> CreateObstacle();
    std::vector<Alien> CreateAlian();

    Sound explosion;

public:
    Game();
    ~Game();

    Music music;

    int lives;
    int score;
    int highscore;
    bool run;

    void Draw();
    void Update();
    void HandleInput();

};
