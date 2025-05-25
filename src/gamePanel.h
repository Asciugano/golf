#pragma once
#include <raylib.h>
#include "ball.h"
#include "buca.h"

class GamePanel
{
private:
    void Reset();
public:
    int tiri;
    const float screenWidth = 500;
    const float screenHeigth = 800;
    Ball ball = Ball(250, 400);
    Buca buca = Buca({250, 30});

    GamePanel();
    ~GamePanel();
    
    void Draw();
    void Update();
};