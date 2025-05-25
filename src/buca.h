#pragma once
#include <raylib.h>
#include "ball.h"

class Buca
{
private:
    float radius;
    const float maxEntrySpeed = 2.7; 
public:
    Vector2 position;

    Buca(Vector2 position);
    ~Buca();
    
    void Draw();
    bool Update(Ball &ball);
};