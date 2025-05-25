#include "gamePanel.h"

GamePanel::GamePanel() {
    tiri = 0;
}

GamePanel::~GamePanel() {}

void GamePanel::Draw()
{
    buca.Draw();
    ball.Draw();
}

void GamePanel::Update()
{
    if(GetKeyPressed() == KEY_R) {
        Reset();
    }
    buca.Update(ball);
    ball.Update();
}

void GamePanel::Reset()
{
    ball = Ball(250, 400);
    tiri = 0;
}