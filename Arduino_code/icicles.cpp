#include "icicles.h"
using namespace DirectionInput;

Icicles::Icicles() : DisplayProcess(3) {
  dripColumn_[0] = 1;  //sets x positions of icicles
  dripColumn_[1] = 2;
  dripColumn_[2] = 4;
  dripColumn_[3] = 6;

  for (uint8_t i = 0; i < 4; ++i)  //init y position of every drip
    dripRow_[i] = 0;
}

void Icicles::init() {
  deepCopyFrame(iciclesFrame);  //base frame in PROGMEM
  updateDisplay();

  for (uint8_t i = 0; i < 4; ++i)  //resets drip row
    dripRow_[i] = 0;

  cycleCounter_ = 0;
}

void Icicles::run(MoveDirection input) {
  //go through each drip column: if 0 roll chance to drip, if not zero drip down one pixel
  //if row is 15 drip step resets to 0

  if (cycleCounter_ < cyclesPerFrame_) {  //animation not ready for next frame
    cycleCounter_++;
    return;
  }

  deepCopyFrame(iciclesFrame);  //resets frame so drips can be moved

  for (uint8_t i = 0; i < 4; ++i) {
    if (dripRow_[i] == 0) {  //if no pixel dripping, rolls for a new pixel to fall
      if (random(100) > 90)
        dripRow_[i]++;
      dripPixel(i);  //moves pixel drip down
    }
    else {  //pixel is already falling in column
      dripRow_[i]++;  //moves drip one pixel down
      dripPixel(i);
    }
  }

  updateDisplay();
  cycleCounter_ = 0;
}

void Icicles::dripPixel(uint8_t index) {
  //if drip has reached bottom; removes drip
  if (dripRow_[index] <= 15) {
    frameBuffer_[dripRow_[index]] |= (0x01 << (7 - dripColumn_[index]));  //moves 1 to column of drip
  }
  else {
    dripRow_[index] = 0;
  }
}