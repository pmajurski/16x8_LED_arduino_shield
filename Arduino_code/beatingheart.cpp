#include "beatingheart.h"
using namespace DirectionInput;

BeatingHeart::BeatingHeart() : DisplayProcess() {
  currentFrame_ = 0;
  displayTimes_[0] = 50;
  displayTimes_[1] = displayTimes_[2] = displayTimes_[3] = 20;
}

void BeatingHeart::init() {
  deepCopyFrame(heart_beat1);
  cycleCounter_ = 0;
  currentFrame_ = 0;
  updateDisplay();
}

void BeatingHeart::run(MoveDirection input) {
  if (cycleCounter_ < displayTimes_[currentFrame_]) {  //animation not ready for next frame
    cycleCounter_++;
    return;
  }

  switch (currentFrame_) {  //if time req met, changes to next frame
    case 0:
      deepCopyFrame(heart_beat2);
      break;
    case 1:
      deepCopyFrame(heart_beat1);
      break;
    case 2:
      deepCopyFrame(heart_beat2);
      break;
    case 3:
      deepCopyFrame(heart_beat1);
  }

  //sets next frame index
  if (currentFrame_ < NUM_ANIMATION_FRAMES - 1)
    currentFrame_++;
  else
    currentFrame_ = 0;

  cycleCounter_ = 0;
  updateDisplay();
}
