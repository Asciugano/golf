#include "ball.h"

Ball::Ball(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
    dragEnd = position;
    velocity = {0, 0};
    entrata = false;
}

Ball::~Ball() {}

void Ball::Draw()
{
    if (!entrata)
        DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::Update()
{
    if (!entrata)
    {
        Vector2 mouse = GetMousePosition();

        float dx = mouse.x - this->position.x;
        float dy = mouse.y - this->position.y;
        float distance = sqrt(dx * dx + dy * dy);

        if (!dragging && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && distance <= radius && !isMoving)
        {
            dragging = true;
        }

        if (dragging)
        {
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                dragEnd = GetMousePosition();
                velocity.x = (position.x - dragEnd.x) * 0.1f;
                velocity.y = (position.y - dragEnd.y) * 0.1f;
                dragging = false;
            }

            Vector2 dir = {mouse.x - position.x, mouse.y - position.y};
            float len = sqrt(dir.x * dir.x + dir.y * dir.y);

            if (len != 0)
            {
                dir.x /= len;
                dir.y /= len;

                Vector2 perp = {-dir.y, dir.x};

                Vector2 base1 = {position.x + perp.x * 10, position.y + perp.y * 10};
                Vector2 base2 = {position.x - perp.x * 10, position.y - perp.y * 10};

                DrawTriangle(base2, base1, mouse, RED);
            }
        }
        else
        {
            position.x += velocity.x;
            position.y += velocity.y;

            if (position.x - radius / 2 <= 0 || position.x + radius / 2 >= GetScreenWidth())
                velocity.x = -velocity.x;
            if (position.y - radius / 2 <= 0 || position.y + radius / 2 >= GetScreenHeight())
                velocity.y = -velocity.y;

            velocity.x *= 0.98f;
            velocity.y *= 0.98f;

            float speed = sqrt(velocity.x * velocity.y + velocity.y * velocity.y);
            if (speed < 0.1f)
            {
                isMoving = false;
                velocity = {0, 0};
            }
            else
                isMoving = true;
        }
    }
}

float Ball::GetRadius()
{
    return this->radius;
}

bool Ball::GetIsMoving() {
    return isMoving;
}