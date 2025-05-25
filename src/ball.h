#pragma once
#include <raylib.h>
#include <iostream>

class Ball {
private:
    float radius = 10;
    bool isMoving = false;
    
    Vector2 velocity;
    Vector2 dragEnd;
    bool dragging = false;
public:
    Vector2 position;
    bool entrata;

    Ball(float x, float y);
    ~Ball();
    
    void Draw();
    void Update();
    
    float GetRadius();
};