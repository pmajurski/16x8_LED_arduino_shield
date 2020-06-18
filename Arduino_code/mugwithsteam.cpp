#include "mugwithsteam.h"
using namespace DirectionInput;

MugWithSteam::MugWithSteam() : DisplayProcess(50) {
  prevPixelSpawn = 0;
}

void MugWithSteam::init() {
  cycleCounter_ = 0;
  deepCopyFrame(mugFrame);  //mug frame in PROGMEM
  updateDisplay();
}

void MugWithSteam::run(MoveDirection input) {
  if (cycleCounter_ < cyclesPerFrame_) {  //animation not ready for next frame
    cycleCounter_++;
    return;
  }

  frameBuffer_[0] = 0x00;  //clears steam pixels from top of screen

  for (uint8_t i = 1; i < 10; ++i) {  //moves current steam pixels up one; y=10 is rim of mug
    frameBuffer_[i-1] = frameBuffer_[i];
    frameBuffer_[i] = 0x00;
  }

  //generates new steam pixel at rim of mug on average once every 2 seconds
  //top of mug is 6 up from bottom, rim is row 10
  if (random(10) > 3) {
    uint8_t position = random(3,7);  //prevents new steam pixel from spawning underneath the last one
    while (position == prevPixelSpawn)
      position = random(3,7);

    frameBuffer_[9] = (0x01 << position);  //steam spawned position random above mug rim
    prevPixelSpawn = position;
  }

  cycleCounter_ = 0;
  updateDisplay();
}