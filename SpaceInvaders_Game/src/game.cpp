#include "game.hpp"
#include <fstream>

void Game::DeleteInactiveLaser()
{
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();)
    {
        if (it->active == false)
        {
            it = spaceship.lasers.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto it = alienslasers.begin(); it != alienslasers.end();)
    {
        if (it->active == false)
        {
            it = alienslasers.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Game::MoveAliens()
{
    for (auto &alien : aliens)
    {
        if ((alien.position.x + alien.alienimages[alien.type - 1].width) > GetScreenWidth() - 25)
        {
            direction = -1;
            MoveDownAliens(4);
        }
        if (alien.position.x < 25)
        {
            direction = 1;
            MoveDownAliens(4);
        }

        alien.Update(direction);
    }
}

void Game::MoveDownAliens(int distance)
{
    for (auto &alien : aliens)
    {
        alien.position.y += distance;
    }
}

void Game::AlienShootLaser()
{
    double currenttime = GetTime();
    if (currenttime - timelastalienfired >= alienlasershootinterval && !aliens.empty())
    {
        int randomindex = GetRandomValue(0, aliens.size() - 1);
        Alien &alien = aliens[randomindex];
        alienslasers.push_back(Laser({alien.position.x + (alien.alienimages[alien.type - 1].width / 2), alien.position.y + (alien.alienimages[alien.type - 1].height / 2)}, 6));
        timelastalienfired = GetTime();
    }
}

void Game::CheckCollision()
{
    for (auto &laser : spaceship.lasers)
    {
        auto it = aliens.begin();
        while (it != aliens.end())
        {
            if (CheckCollisionRecs(it->GetRect(), laser.GetRect()))
            {
                PlaySound(explosion);
                if (it->type == 1)
                {
                    score += 100;
                }
                else if (it->type == 2)
                {
                    score += 200;
                }
                else if (it->type == 3)
                {
                    score += 300;
                }
                CheckForHighScore();

                it = aliens.erase(it);
                laser.active = false;
            }
            else
            {
                it++;
            }
        }

        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->GetRect(), laser.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    it++;
                }
            }
        }

        if (CheckCollisionRecs(mysteryship.GetRect(), laser.GetRect()))
        {
            PlaySound(explosion);
            score += 500;
            mysteryship.alive = false;
            laser.active = false;
            CheckForHighScore();
        }
    }

    for (auto &laser : alienslasers)
    {
        if (CheckCollisionRecs(laser.GetRect(), spaceship.GetRect()))
        {
            laser.active = false;
            lives--;
            if (lives <= 0)
            {
                GameOver();
            }
        }

        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->GetRect(), laser.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    it++;
                }
            }
        }
    }

    for (auto &alien : aliens)
    {
        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->GetRect(), alien.GetRect()))
                {
                    it = obstacle.blocks.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }

        if (CheckCollisionRecs(alien.GetRect(), spaceship.GetRect()))
        {
            GameOver();
        }
    }
}

void Game::Reset()
{
    spaceship.Reset();
    aliens.clear();
    alienslasers.clear();
    obstacles.clear();
}

void Game::InitGame()
{
    obstacles = CreateObstacle();
    aliens = CreateAlian();
    direction = 1;
    timelastalienfired = 0.0;
    timelastspawn = 0.0;
    mysteryshipspawninterval = GetRandomValue(10, 20);
    lives = 3;
    score = 0;
    highscore = 0;
    run = true;
    LoadHighScore();
}

void Game::GameOver()
{
    run = false;
}

void Game::CheckForHighScore()
{
    if (score > highscore)
    {
        highscore = score;
        SaveHighScore();
    }
}

void Game::SaveHighScore()
{
    std::ofstream file("highscore.txt");
    if (file.is_open())
    {
        file << highscore;
        file.close();
    }
}

void Game::LoadHighScore()
{
    std::ifstream file("highscore.txt");
    if (file.is_open())
    {
        file >> highscore;
        file.close();
    }
    else
    {
        highscore = 0;
    }
}

std::vector<Obstacle> Game::CreateObstacle()
{
    int obstacle_width = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (obstacle_width * 4)) / 5;

    for (int i = 0; i < 4; i++)
    {
        float offset_x = (i + 1) * gap + i * obstacle_width;
        obstacles.push_back(Obstacle({offset_x, float(GetScreenHeight() - 200)}));
    }
    return obstacles;
}

std::vector<Alien> Game::CreateAlian()
{
    std::vector<Alien> alians;

    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 11; col++)
        {
            int alien_type = 1;

            if (row == 0)
            {
                alien_type = 3;
            }
            else if (row == 1 || row == 2)
            {
                alien_type = 2;
            }

            alians.push_back(Alien(alien_type, {float(75 + col * 55), float(110 + row * 55)}));
        }
    }

    return alians;
}

Game::Game()
{
    music = LoadMusicStream("Sounds/music.ogg");
    PlayMusicStream(music);

    explosion = LoadSound("Sounds/explosion.ogg");
    InitGame();
}

Game::~Game()
{
    UnloadMusicStream(music);
    UnloadSound(explosion);
    Alien::UnloadAlienImages();
}

void Game::Draw()
{
    spaceship.Draw();

    for (auto &laser : spaceship.lasers)
    {
        laser.Draw();
    }
    for (auto &obstacle : obstacles)
    {
        obstacle.Draw();
    }
    for (auto &alien : aliens)
    {
        alien.Draw();
    }
    for (auto &laser : alienslasers)
    {
        laser.Draw();
    }
    mysteryship.Draw();
}

void Game::Update()
{
    if (run)
    {
        double currenttime = GetTime();
        if (currenttime - timelastspawn > mysteryshipspawninterval)
        {
            mysteryship.Spawn();
            timelastspawn = GetTime();
            mysteryshipspawninterval = GetRandomValue(10, 20);
        }

        for (auto &laser : spaceship.lasers)
        {
            laser.Update();
        }

        AlienShootLaser();

        for (auto &laser : alienslasers)
        {
            laser.Update();
        }

        DeleteInactiveLaser();
        MoveAliens();
        mysteryship.Update();
        CheckCollision();
    }
    else
    {
        if (IsKeyDown(KEY_ENTER))
        {
            Reset();
            InitGame();
        }
    }
}

void Game::HandleInput()
{
    if (run)
    {
        if (IsKeyDown(KEY_LEFT))
        {
            spaceship.MoveLeft();
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            spaceship.MoveRight();
        }
        if (IsKeyDown(KEY_SPACE))
        {
            spaceship.FireLaser();
        }
    }
}
