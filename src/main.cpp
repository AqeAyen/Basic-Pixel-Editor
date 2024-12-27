#include "raylib.h"
#include <stdio.h>
#include <vector>
struct Pixel {
  float x, y;
  float width, height;
  Color color;
};

void UserDraw(float width, float height, Color &color,
              std::vector<Pixel> &pixels) {
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    pixels.push_back(
        {(float)GetMouseX(), (float)GetMouseY(), width, height, color});
  }
  for (const auto &pixel : pixels) {
    DrawRectangle(pixel.x, pixel.y, pixel.width, pixel.height, pixel.color);
  }
}

void DrawColorPallete(float x, float y, float rectSize, Color &selectedColor,
                      std::vector<Color> &pallete) {
  // Draws the pallete
  for (size_t i = 0; i < pallete.size(); i++) {
    Rectangle colorBox = {x, y + i * (rectSize + 5), rectSize, rectSize};
    DrawRectangleRec(colorBox, pallete[i]);
    // Checks if the mouse hovers over the pallete and if so highlights them
    if (CheckCollisionPointRec(GetMousePosition(), colorBox)) {
      DrawRectangleLinesEx(colorBox, 2, BLACK);
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        selectedColor = pallete[i];
      }
    }
  }

  DrawRectangle(x, y - rectSize, rectSize, rectSize, selectedColor);
  DrawRectangleLines(x, y - rectSize, rectSize, rectSize, BLACK);
}
int main(int argc, char **argv) {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;

  InitWindow(SCREEN_WIDTH, SCREEN_WIDTH, "Pixel");

  std::vector<Pixel> pixels;
  std::vector<Color> pallete = {RED, GREEN, BLUE, YELLOW, ORANGE};
  Color userColor = WHITE;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    // This is where we update our variables

    BeginDrawing(); // We Draw stuff inside m here

    ClearBackground(WHITE);
    UserDraw(32, 32, userColor, pixels);
    DrawColorPallete(700, 50, 30, userColor, pallete);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
