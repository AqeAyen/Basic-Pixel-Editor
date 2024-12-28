#include <raylib.h>
#include <vector>
struct Pixel {
  float x, y;
  float width, height;
  Color color;
};
struct PixelState {
  std::vector<Pixel> pixels;
};
