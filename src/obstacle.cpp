#include "obstacle.h"

Obstacle::Obstacle(Vector2 position)
{
    this->position = position;
}

Obstacle::~Obstacle() {}

void Obstacle::Draw(Color color)
{
    DrawRectangle(position.x, position.y, size, size, color);
}

void Obstacle::Update(Ball &ball)
{
    float ballLeft = ball.position.x - ball.GetRadius();
    float ballRight = ball.position.x + ball.GetRadius();
    float ballTop = ball.position.y - ball.GetRadius();
    float ballBottom = ball.position.y + ball.GetRadius();

    float obsLeft = position.x;
    float obsRight = position.x + size;
    float obsTop = position.y;
    float obsBottom = position.y + size;

    bool collisionX = ballRight > obsLeft && ballLeft < obsRight;
    bool collisionY = ballBottom > obsTop && ballTop < obsBottom;

    if (collisionX && collisionY)
    {
        ball.SetHitted(true);

        float overlapX = std::min(ballRight, obsRight) - std::max(ballLeft, obsLeft);
        float overlapY = std::min(ballBottom, obsBottom) - std::max(ballTop, obsTop);

        if (overlapX > 0.0f && overlapY > 0.0f)
        {
            if (overlapX < overlapY)
            {
                ball.velocity.x = -ball.velocity.x;
                if (ball.position.x < position.x)
                    ball.position.x = obsLeft - ball.GetRadius();
                else
                    ball.position.x = obsRight + ball.GetRadius();
            }
            else
            {
                ball.velocity.y = -ball.velocity.y;
                if (ball.position.y < position.y)
                    ball.position.y = obsTop - ball.GetRadius();
                else
                    ball.position.y = obsBottom + ball.GetRadius();
            }
        }
    }
}