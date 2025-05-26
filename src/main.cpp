#include <raylib.h>
#include "gamePanel.h"

int main()
{
  GamePanel gamePanel;

  InitWindow(gamePanel.screenWidth, gamePanel.screenHeigth, "GOLF");

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    gamePanel.DrawCenteredText(("Round: " + std::to_string(gamePanel.GetRound())).c_str(), 4, 36, WHITE);

    gamePanel.Update();

    gamePanel.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}