#include "gamePanel.h"

GamePanel::GamePanel()
{
    round = 1;
    tiri = 1;
}

GamePanel::~GamePanel() {}

void GamePanel::Draw()
{
    if(showText)
    {
        DrawCenteredText(message.c_str(), 400, 36, WHITE);
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
    
    if(showText)
    {
        messageTimer += GetFrameTime();
        if(messageTimer >= 0.90)
        {
            showText = false;
            messageTimer = 0;
        }
    }

    ball.Update();
    if(!ball.GetIsMoving() && ballIsMoving) 
    {
        ballIsMoving = false;
        tiri++;
    }
    else if(ball.GetIsMoving())
    {
        ballIsMoving = true;
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

void GamePanel::DrawCenteredText(const std::string& text, int y, int fontSize, Color color)
{
    int textWidth = MeasureText(text.c_str(), fontSize);
    int x = (GetScreenWidth() - textWidth) / 2;

    DrawText(text.c_str(), x, y, fontSize, color);
}