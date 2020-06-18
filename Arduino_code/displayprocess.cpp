#include "displayprocess.h"
using namespace DirectionInput;

DisplayDriver DisplayProcess::display_ = DisplayDriver();  //LED display driver class
uint8_t DisplayProcess::frameBuffer_[16] = {0};  //init static members
uint8_t DisplayProcess::gameMatrix_[16][8] = { {0} };


DisplayProcess::DisplayProcess(uint8_t cyclesPerFrame) : isPaused_(false), moveBuffer_(NO_INPUT),
                                                         cycleCounter_(0), cyclesPerFrame_(cyclesPerFrame) {}

void DisplayProcess::increaseBrightness() { display_.increaseBrightness(); }

void DisplayProcess::decreaseBrightness() { display_.decreaseBrightness(); }

void DisplayProcess::pause() { isPaused_ = true; }

void DisplayProcess::unpause() { isPaused_ = false; }

void DisplayProcess::resetFrameBuffer() {
  for (uint8_t i = 0; i < 16; ++i) {
    frameBuffer_[i] = 0x00;
  }
}

void DisplayProcess::deepCopyFrame(const uint8_t frame[]) {
  for (uint8_t i = 0; i < 16; ++i) {
    frameBuffer_[i] = pgm_read_byte_near(frame + i);
  }
}

void DisplayProcess::resetGameMatrix() {
  for (uint8_t y = 0; y < 16; ++y) {
    for (uint8_t x = 0; x < 8; ++x) {
      gameMatrix_[y][x] = 0;
    }
  }
}

void DisplayProcess::writeToFrameBuffer(const uint8_t arr[4], int8_t row) {
  for (int8_t i = 0; i < 4; ++i) {
    if (inBounds(row + i, 0))  //ignores rows that are out of bounds
      frameBuffer_[row + i] = arr[i];  //overwrites row in frame buffer
  }
}

bool DisplayProcess::inBounds(int8_t y, int8_t x) {
  if (y < 0 or y > 15)
    return false;
  if (x < 0 or x > 7)
    return false;
  return true;
}

void DisplayProcess::writeMatrixToFrame() {
  uint8_t rowBuffer = 0;
  for (uint8_t y = 0; y < 16; ++y) {
    rowBuffer = 0;
    for (uint8_t x = 0; x < 8; ++x) {
      if (gameMatrix_[y][x] != 0) {
        rowBuffer |= (0x01 << (7 - x));  //bit shifts 1 to column in row
      }
    }
    frameBuffer_[y] = rowBuffer;  //updates frame
  }
}

void DisplayProcess::updateDisplay() { display_.updateDisplay(frameBuffer_); }
