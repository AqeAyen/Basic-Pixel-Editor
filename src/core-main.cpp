#include "../include/main.h"
#include <raylib.h>
#include <stack>

void SaveState(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
               std::stack<PixelState> &redostack) {
  undostack.push({pixels});
  while (!redostack.empty()) {
    redostack.pop();
  }
}

void undo(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
          std::stack<PixelState> &redostack) {
  if (!undostack.empty()) {
    redostack.push({pixels});
    // store the PixelState
    pixels = undostack.top().pixels;
    // restore the last save state
    undostack.pop();
  }
}

void redo(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
          std::stack<PixelState> &redostack) {
  if (!redostack.empty()) {
    undostack.push({pixels});
    // store the pixelstate
    pixels = redostack.top().pixels;
    // restore the last state
    redostack.pop();
  }
}

void DrawButtons(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
                 std::stack<PixelState> &redostack) {
  Rectangle undoButton = {10, 60, 80, 40};
  Rectangle redoButton = {100, 60, 80, 40};

  DrawRectangleRec(undoButton, LIGHTGRAY);
  DrawText("Undo", undoButton.x + 10, undoButton.y + 10, 20, BLACK);
  DrawRectangleRec(redoButton, LIGHTGRAY);
  DrawText("Redo", redoButton.x + 10, redoButton.y + 10, 20, BLACK);

  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mouse = GetMousePosition();
    if (CheckCollisionPointRec(mouse, undoButton)) {
      undo(pixels, undostack, redostack);
    } else if (CheckCollisionPointRec(mouse, redoButton)) {
      redo(pixels, undostack, redostack);
    }
  }
}
