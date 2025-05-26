#include "gamePanel.h"

GamePanel::GamePanel()
{
    round = 1;
    tiri = 1;
    for (float y = 100; y < 400; y += 50)
    {
        obstacles.push_back(Obstacle({100, y}));
    }
}

GamePanel::~GamePanel() {}

void GamePanel::Draw()
{
    DrawLinearCourt();
    if (showText)
    {
        DrawCenteredText(message.c_str(), 400, 36, WHITE);
    }
    for (Obstacle obstacle : obstacles)
    {
        obstacle.Draw(BROWN);
    }
    buca.Draw();
    ball.Draw();
}

void GamePanel::Update()
{
    if (GetKeyPressed() == KEY_R)
    {
        Reset();
    }
    if (buca.Update(ball))
    {
        round++;
        message = tiri > 1 ? ("Imbucata con: " + std::to_string(tiri) + " tiri").c_str() : "Hole in one";
        showText = true;
        Reset();
    }

    if (showText)
    {
        messageTimer += GetFrameTime();
        if (messageTimer >= 0.90)
        {
            showText = false;
            messageTimer = 0;
        }
    }

    ball.Update();
    if (!ball.GetIsMoving() && ballIsMoving)
    {
        ballIsMoving = false;
        tiri++;
    }
    else if (ball.GetIsMoving())
    {
        ballIsMoving = true;
    }
    for (Obstacle obstacle : obstacles)
    {
        obstacle.Update(ball);
    }
}

void GamePanel::Reset()
{
    ball = Ball(250, 600);
    tiri = 0;
}

int GamePanel::GetRound()
{
    return round;
}

void GamePanel::DrawCenteredText(const std::string &text, int y, int fontSize, Color color)
{
    int textWidth = MeasureText(text.c_str(), fontSize);
    int x = (GetScreenWidth() - textWidth) / 2;

    DrawText(text.c_str(), x, y, fontSize, color);
}

void GamePanel::DrawSquaredCourt()
{
    bool dark = false;
    for (int x = 0; x < GetScreenWidth(); x += 50)
    {
        for (int y = 0; y < GetScreenHeight(); y += 50)
        {
            DrawRectangle(x, y, 50, 50, !dark ? GREEN : DARKGREEN);
            dark = !dark;
        }
        dark = !dark;
    }
}

void GamePanel::DrawLinearCourt()
{
    bool dark = false;
    for (int x = 0; x < GetScreenWidth(); x += 50)
    {
        DrawRectangle(x, 0, 50, GetScreenHeight(), !dark ? GREEN : DARKGREEN);
        dark = !dark;
    }
}