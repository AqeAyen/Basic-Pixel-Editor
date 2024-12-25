#include "raylib.h"

int main(int argc, char **argv) {
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 400;

  InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "Pixel");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // This is where we update our variables

    BeginDrawing(); // We Draw stuff inside m here

    ClearBackground(WHITE);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
