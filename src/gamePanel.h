#pragma once
#include <raylib.h>
#include <vector>
#include <string>
#include "obstacle.h"
#include "ball.h"
#include "buca.h"

class GamePanel
{
private:
    void Reset();
    int round;
    
    bool ballIsMoving = false;
    
    bool showText = false;
    float messageTimer = 0;
    std::string message;
    
    std::vector<Obstacle> obstacles;
    
    void DrawSquaredCourt();
    void DrawLinearCourt();

public:
    int tiri;
    const float screenWidth = 500;
    const float screenHeigth = 800;

    Ball ball = Ball(250, 600);
    Buca buca = Buca({250, 70});

    GamePanel();
    ~GamePanel();

    void Draw();
    void Update();

    int GetRound();
    
    void DrawCenteredText(const std::string& text, int y, int fontSize, Color color);
};