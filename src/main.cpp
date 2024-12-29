#include "../include/main.h"
#include "../include/slider.h"
#include "raylib.h"
#include <stack>
#include <stdio.h>
#include <vector>

void UserDraw(float width, float height, Color &color,
              std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
              std::stack<PixelState> &redostack) {
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    SaveState(pixels, undostack, redostack);
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
  std::stack<PixelState> undoStack, redoStack;
  std::vector<Color> pallete = {RED, GREEN, BLUE, YELLOW, ORANGE, BLACK, WHITE};
  Color userColor = WHITE;
  float pixelWidth = 32;
  float pixelHeight = 32;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Z)) {
      undo(pixels, undoStack, redoStack);
    }
    if (IsKeyPressed(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_Y)) {
      redo(pixels, undoStack, redoStack);
    }
    // This is where we update our variables

    BeginDrawing(); // We Draw stuff inside m here

    ClearBackground(WHITE);

    UserDraw(pixelWidth, pixelHeight, userColor, pixels, undoStack, redoStack);
    float newSize = DrawSlider(10, 10, 200, 1, 64, pixelWidth);
    pixelWidth = newSize;
    pixelHeight = newSize;

    DrawColorPallete(700, 50, 30, userColor, pallete);
    DrawText(TextFormat("Size %.0f", pixelWidth), 10, 40, 20, BLACK);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
