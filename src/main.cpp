#include <raylib.h>
#include "gamePanel.h"

int main() {
  GamePanel gamePanel;

  InitWindow(gamePanel.screenWidth, gamePanel.screenHeigth, "GOLF");
  
  SetTargetFPS(60);
  
  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GREEN);
    
    gamePanel.Update();

    gamePanel.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
