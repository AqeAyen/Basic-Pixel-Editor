#include "raylib.h"
#include <stdio.h>
#include <vector>
struct Pixel {
  float x, y;
  float width, height;
  Color color;
};

void UserDraw(float width, float height, Color color,
              std::vector<Pixel> &pixels) {
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    pixels.push_back(
        {(float)GetMouseX(), (float)GetMouseY(), width, height, color});
  }
  for (const auto &pixel : pixels) {
    DrawRectangle(pixel.x, pixel.y, pixel.width, pixel.height, pixel.color);
  }
}
int main(int argc, char **argv) {
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 400;

  InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "Pixel");

  std::vector<Pixel> pixels;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // This is where we update our variables

    BeginDrawing(); // We Draw stuff inside m here

    ClearBackground(WHITE);
    UserDraw(32, 32, BLACK, pixels);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
