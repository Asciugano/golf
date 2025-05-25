#include <raylib.h>
#include "ball.h"

int main() {
  InitWindow(500, 800, "GOLF");
  
  Ball ball = Ball(250, 400);
  
  SetTargetFPS(60);
  
  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GREEN);
    ball.Update();
    
    ball.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
