#include "ball.h"

Ball::Ball(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
    // this->speed = 5;
    velocity = {0, 0};
}

Ball::~Ball() {}

void Ball::Draw()
{
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::Update()
{
    Vector2 mouse = GetMousePosition();
    Vector2 dragEnd;
    
    float dx = mouse.x - this->position.x;
    float dy = mouse.y - this->position.y;
    float distance = sqrt(dx * dx + dy * dy);

    if (!dragging && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && distance <= radius)
    {

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            dragging = true;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            dragEnd = GetMousePosition();
            dragging = false;

            velocity.x = (position.x - dragEnd.x) * 0.1f;
            velocity.y = (position.y - dragEnd.y) * 0.1f;
        }
        
        position.x += velocity.x;
        position.y += velocity.y;
        
        velocity.x *= 0.98f;
        velocity.y *= 0.98f;

        if (dragging)
        {
            Vector2 current = GetMousePosition();

            DrawLine(position.x, position.y, current.x, current.y, RED);
        }
    }
}