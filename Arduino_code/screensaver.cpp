#include "screensaver.h"
using namespace DirectionInput;

ScreenSaver::ScreenSaver() : DisplayProcess(35) {
  yPos_ = xPos_ = 0;
  dy_ = dx_ = 1;
}

void ScreenSaver::init() {
  cycleCounter_ = 0;

  //random start coordinates
  yPos_ = random(UPPER_Y_BOUND + 1);
  xPos_ = random(UPPER_X_BOUND + 1);

  //random start direction
  dy_ = random(2);
  dx_ = random(2);
  if (dy_ == 0)
    dy_ = -1;
  if (dx_ == 0)
    dx_ = -1;

  resetGameMatrix();
  updateBlockSprite(1);  //writes block to game matrix
  writeMatrixToFrame();
  updateDisplay();
}

void ScreenSaver::run(MoveDirection input) {
  if (cycleCounter_ < cyclesPerFrame_) {  //animation not ready for next frame
    cycleCounter_++;
    return;
  }

  updateBlockSprite(0);  //clears block sprite in game matrix

  //block will change both x and y direction if it hits a corner
  if (yPos_ == 0)  //block hits ceiling or floor, changes y direction
    dy_ = 1;
  else if (yPos_ == UPPER_Y_BOUND)
    dy_ = -1;

  if (xPos_ == 0)  //block hits left or right wall, changes x direction
    dx_ = 1;
  else if (xPos_ == UPPER_X_BOUND)
    dx_ = -1;

  yPos_ += dy_;  //updates block position
  xPos_ += dx_;

  updateBlockSprite(1);  //writes block to game matrix
  writeMatrixToFrame();
  updateDisplay();
  cycleCounter_ = 0;
}

void ScreenSaver::updateBlockSprite(uint8_t pixelState) {
  for (int8_t y = 0; y < 2; ++y) {
    for (int8_t x = 0; x < 2; ++x) {
      gameMatrix_[yPos_ + y][xPos_ + x] = pixelState;
    }
  }
}
