#include "inchworm.h"
using namespace DirectionInput;

InchWorm::InchWorm() : DisplayProcess(35){
  wall_ = LEFT;
  wormX_ = wormY_ = wormDY_ = wormDX_ = currentSprite_ = 0;
}

void InchWorm::init() {
  cycleCounter_ = 0;

  wall_ = (MoveDirection) random(1,5);  //randomizes worm starting wall
  switchWall();

  resetFrameBuffer();  //clears current sprite
  writeToFrameBuffer(sprites_[currentSprite_], wormY_);
  updateDisplay();
}

void InchWorm::run(MoveDirection input) {
  if (cycleCounter_ < cyclesPerFrame_) {  //animation not ready for next frame
    cycleCounter_++;
    return;
  }

  moveTheWorm();  //updates animation
  cycleCounter_ = 0;
}

void InchWorm::moveTheWorm() {
  if (currentSprite_ > 1) {  //worm is in a corner
    if (currentSprite_ == EXIT_CORNER)
      switchWall();
    else  //moves to next corner sprite
      currentSprite_++;
  }
  else if (wormOutOfBounds(wormY_ + wormDY_, wormX_ + wormDX_)) {
    currentSprite_ = ENTER_CORNER;
  }
  else {  //standard worm move; not in a corner
    updateWormSprite();
  }

  resetFrameBuffer();  //clears current sprite
  writeToFrameBuffer(sprites_[currentSprite_], wormY_);
  updateDisplay();
}

void InchWorm::updateWormSprite() {
  if (currentSprite_ == CURLED) {  //swaps current sprite to CURLED
    currentSprite_ = STRAIGHT;
    return;  //worm coordinates do not change
  }

  //currentSprite_ == STRAIGHT; changes to STRAIGHT
  currentSprite_ = CURLED;

  //worm coordinates change on transition from CURLED to STRAIGHT
  if (wall_ == LEFT or wall_ == RIGHT) {  //sprite shifted by one row up / down
    wormY_ += wormDY_;
  }
  else if (wall_ == UP) {  //worm sprite shifted one to the right [clockwise]
    wormX_ += wormDX_;

    for (uint8_t i = 0; i < 4; ++i) {  //right bitshift of STRAIGHT and CURLED sprites
      sprites_[STRAIGHT][i] = (sprites_[STRAIGHT][i] >> 1);
      sprites_[CURLED][i] = (sprites_[CURLED][i] >> 1);
    }
  }
  else if (wall_ == DOWN) {  //worm sprite shifted one to the left [clockwise]
    wormX_ += wormDX_;

    for (uint8_t i = 0; i < 4; ++i) {  //left bitshift of STRAIGHT and CURLED sprites
      sprites_[STRAIGHT][i] = (sprites_[STRAIGHT][i] << 1);
      sprites_[CURLED][i] = (sprites_[CURLED][i] << 1);
    }
  }
}

void InchWorm::switchWall() {
  currentSprite_ = CURLED;  //first sprite on each wall is curled
  const uint8_t (*p)[5][4];  //pointer to sprites in PROGMEM

  if (wall_ == LEFT) {  //coord [0,0]->[0,5], worm on ceiling
    wall_ = UP;
    wormDY_ = 0; wormDX_ = 1;
    wormY_ = 0; wormX_ = 0;
    p = &wormSpritesTop;
  }
  else if (wall_ == UP) {  //coord [0,4]->[13,4], worm on right wall
    wall_ = RIGHT;
    wormDY_ = 1; wormDX_ = 0;
    wormY_ = 0; wormX_ = 4;
    p = &wormSpritesRight;
  }
  else if (wall_ == RIGHT) {  //coord [12,4]->[12,-1], worm on floor
    wall_ = DOWN;
    wormDY_ = 0; wormDX_ = -1;
    wormY_ = 12; wormX_ = 4;
    p = &wormSpritesBottom;
  }
  else if (wall_ == DOWN) {  //coord [12,0]->[-1,0], worm on left wall
    wall_ = LEFT;
    wormDY_ = -1; wormDX_ = 0;
    wormY_ = 12; wormX_ = 0;
    p = &wormSpritesLeft;
  }

  for (uint8_t y = 0; y < 5; ++y) {  //deep copies sprites from PROGMEM
    for (uint8_t x = 0; x < 4; ++x) {
      sprites_[y][x] = pgm_read_byte_near((*p)[y] + x);
    }
  }
}

bool InchWorm::wormOutOfBounds(int8_t y, int8_t x) {
  //x and y have 1 extra pixel on each side to make corner transition simpler
  if (y < -1 or y > 13)
    return true;
  if (x < -1 or x > 5)
    return true;
  return false;
}