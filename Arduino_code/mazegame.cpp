#include "mazegame.h"
using namespace DirectionInput;

MazeGame::MazeGame() : DisplayProcess(10){
  yPos_ = xPos_ = 0;
  blinkState_ = true;
  gameOver_ = false;
}

void MazeGame::init() {
  isPaused_ = true;
  restartGame();
}

void MazeGame::run(DirectionInput::MoveDirection input) {
  if (isPaused_)
    return;

  if (input != NO_INPUT)  //input is buffered until next game update
    moveBuffer_ = input;

  if (!gameOver_ and cycleCounter_ >= cyclesPerFrame_) {  //game active, updates game
    blinkState_ = !blinkState_;  //blinks cursor
    moveCursor();  //updates cursor
    moveBuffer_ = NO_INPUT;  //clears input buffer
    cycleCounter_ = 0;
  }
  else if (gameOver_ and moveBuffer_ == UP) {  //pressing up resets game
    restartGame();
  }
  else {  //game not ready to update
    cycleCounter_++;
  }
}

bool MazeGame::isValidPosition(int8_t y, int8_t x) {
  //tests if y,x coordinate in inside display area
  if (y < 0 or y > UPPER_Y_BOUND)
    return false;
  if (x < 0 or x > UPPER_X_BOUND)
    return false;

  //tests if position is a wall of the maze
  uint8_t b = frameBuffer_[y];  //row under evaluation

  b = ((b << x) & 0b10000000);  //zeros every bit except for x position [column]
  if (b != 0)  //bit at [x] is a 1: y,x coordinate is a maze wall
    return false;

  return true;
}

void MazeGame::moveCursor() {
  if (yPos_ == FINISH_Y and xPos_ == FINISH_X) {  //cursor is at finish
    gameOver_ = true;
    deepCopyFrame(smileyFace);
    updateDisplay();
    return;
  }

  int8_t dy = 0;
  int8_t dx = 0;
  switch (moveBuffer_) {  //translates moveBuffer into x,y coordinate deltas
    case LEFT:
      dx = -1;
      break;
    case RIGHT:
      dx = 1;
      break;
    case UP:
      dy = -1;
      break;
    case DOWN:
      dy = 1;
  }

  if (isValidPosition(yPos_ + dy, xPos_ + dx)) {  //direction is valid move
    eraseCursor();  //erases cursor from current position
    yPos_ += dy;
    xPos_ += dx;
  }

  drawCursor();  //if moveBuffer is no input, cursor will blink but not move
}

void MazeGame::drawCursor() {
  uint8_t xBit = (0b10000000 >> xPos_);  //x position is 1, other bits are 0

  if (blinkState_)  //cursor is drawn to frame buffer
    frameBuffer_[yPos_] |= xBit;
  else  //cursor is blinked off, erased from frame buffer
    frameBuffer_[yPos_] &= (~xBit);

  updateDisplay();
}

void MazeGame::eraseCursor() {
  uint8_t xBit = (0b10000000 >> xPos_);  //x position is 1, other bits are 0
  frameBuffer_[yPos_] &= (~xBit);
  updateDisplay();
}

void MazeGame::restartGame() {
  deepCopyFrame(maze_16x8);
  gameOver_ = false;
  cycleCounter_ = 0;
  yPos_ = START_Y;
  xPos_ = START_X;
  blinkState_ = false;
  moveBuffer_ = NO_INPUT;

  drawCursor();  //writes maze and cursor to display
}


