#pragma once
#include <raylib.h>
#include <iostream>

class Ball {
private:
    float radius = 10;
    bool isMoving = false;
    
    Vector2 dragEnd;
    bool dragging = false;
    
    bool hitted = false;
    float hittedTime = 0;
    
    void DrawIndicator();
public:
    Vector2 position;
    bool entrata;
    Vector2 velocity;

    Ball(float x, float y);
    ~Ball();
    
    void Draw();
    void Update();
    
    float GetRadius();
    
    bool GetIsMoving();
    void SetHitted(bool hitted);
};