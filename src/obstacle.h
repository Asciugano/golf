#pragma once
#include <raylib.h>
#include "ball.h"

class Obstacle
{
private:
    const float size = 50;
public:
    Vector2 position;

    Obstacle(Vector2 position);
    ~Obstacle();
    
    void Draw(Color color);
    void Update(Ball &ball);
};