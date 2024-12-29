#ifndef MAIN_H
#define MAIN_H
//          ╭─────────────────────────────────────────────────────────╮
//          │                         main.h                          │
//          ╰─────────────────────────────────────────────────────────╯
//          ╭──────────────────────────────────────────────────────────╮
//          │ main.h - Header file for this basic pixel editor         │
//          │ This includes all the core functionalities of this editor│
//          │ this functions includes undo/redo drawing and also       │
//          │ color changing                                           │
//          │ among other things                                       │
//          │                                                          │
//          ╰──────────────────────────────────────────────────────────╯
#include <raylib.h>
#include <stack>
#include <vector>
struct Pixel {
  float x, y;
  float width, height;
  Color color;
};
struct PixelState {
  std::vector<Pixel> pixels;
};

void SaveState(std::vector<Pixel> &pixels);

// undo
void undo(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
          std::stack<PixelState> &redostack);

void redo(std::vector<Pixel> &pixels, std::stack<PixelState> &undostack,
          std::stack<PixelState> &redostack);

#endif /* MAIN_H */
