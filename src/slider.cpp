#include "../include/slider.h"
#include <algorithm>

float DrawSlider(float x, float y, float width, float min, float max,
                 float currentValue) {
  // Draw slider background
  Rectangle sliderBackground = {x, y, width, 20};
  DrawRectangleRec(sliderBackground, LIGHTGRAY);

  // Map the current value to a slider position
  float normalizedValue = (currentValue - min) / (max - min);
  float sliderX = x + normalizedValue * width;

  // Draw slider knob
  Rectangle sliderKnob = {sliderX - 5, y - 5, 10, 30};
  DrawRectangleRec(sliderKnob, DARKGRAY);

  // Check for mouse interaction
  if (CheckCollisionPointRec(GetMousePosition(), sliderBackground) &&
      IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    float mouseX = GetMouseX();
    normalizedValue = (mouseX - x) / width;
    normalizedValue = std::clamp(normalizedValue, 0.0f,
                                 1.0f); // Ensure it stays within bounds
    currentValue = min + normalizedValue * (max - min);
  }

  return currentValue;
}
