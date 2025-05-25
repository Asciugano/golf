#pragma once
#include <raylib.h>
#include <iostream>

class Ball {
private:
    const float radius = 10;
    
    Vector2 velocity;
    Vector2 dragEnd;
    bool dragging = false;
public:
    Vector2 position;

    Ball(float x, float y);
    ~Ball();
    
    void Draw();
    void Update();
};