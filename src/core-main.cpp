#include "../include/main.h"
#include <stack>

void SaveState(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
               std::stack<PixelState> &redostack) {
  undostack.push({pixels});
  while (redostack.empty()) {
    redostack.pop();
  }
}

void undo(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
          std::stack<PixelState> &redostack) {
  if (undostack.empty()) {
    redostack.push({pixels});
    // store the PixelState
    pixels = undostack.top().pixels;
    // restore the last save state
    undostack.pop();
  }
}
