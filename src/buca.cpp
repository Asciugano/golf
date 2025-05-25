#include "buca.h"

Buca::Buca(Vector2 position)
{
    this->position = position;
    radius = 15;
}

Buca::~Buca() {}

void Buca::Draw() 
{
    DrawCircle(position.x, position.y, radius, GRAY);
}

void Buca::Update(Ball &ball) 
{
    float dx = ball.position.x - position.x;
    float dy = ball.position.y - position.y;
    float dist = sqrt(dx * dx + dy * dy);
    
    float speed = sqrt(ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y);

    if(dist < radius + ball.GetRadius() && speed < maxEntrySpeed) {
        ball.entrata = true;
    }
}