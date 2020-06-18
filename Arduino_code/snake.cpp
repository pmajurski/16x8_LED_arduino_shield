#include "snake.h"
using namespace DirectionInput;

Snake::Snake() : DisplayProcess(20) {
  gameOver_ = false;
  snakeLength_ = snakeHeadX_ = snakeHeadY_ = 0;
}

void Snake::init() {
  isPaused_ = true;
  restartGame();
}

void Snake::run(MoveDirection input) {
  if (isPaused_)
    return;

  if (input != NO_INPUT)  //snake will always move, move buffer is not reset on step
    moveBuffer_ = input;

  if (!gameOver_ and cycleCounter_ >= cyclesPerFrame_) {  //game active, updates frame
    moveSnake();
    cycleCounter_ = 0;
  }
  else if (gameOver_ and moveBuffer_ == UP) {  //pressing up resets game
    restartGame();
  }
  else {  //game not ready to step to next frame
    cycleCounter_++;
  }
}

void Snake::placeFood() {
  uint8_t y;
  uint8_t x;

  do {  //loops until empty position found
    y = random(16);
    x = random(8);
  } while (gameMatrix_[y][x] != 0);

  gameMatrix_[y][x] = FOOD_VALUE;  //writes food position
}

void Snake::moveSnake() {
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

  //updates snake head position, wraps around edges of the display
  snakeHeadY_ = (snakeHeadY_ + dy + 16) % 16;
  snakeHeadX_ = (snakeHeadX_ + dx + 8) % 8;
  uint8_t position = gameMatrix_[snakeHeadY_][snakeHeadX_];

  if (position == FOOD_VALUE) {  //food encountered
    snakeLength_++;
    gameMatrix_[snakeHeadY_][snakeHeadX_] = snakeLength_;
    placeFood();  //new food placed
    writeMatrixToFrame();
  }
  else if (position != 0) {  //collision; displays game over image
    gameOver_ = true;
    moveBuffer_ = NO_INPUT;  //clears moveBuffer for game over screen input
    deepCopyFrame(neutralFace);  //game over frame in PROGMEM
  }
  else {  //empty space encountered; moves snake
    gameMatrix_[snakeHeadY_][snakeHeadX_] = snakeLength_ + 1;

    //decreases each element in game matrix by 1, "moving" the snake forward
    for (uint8_t y = 0; y < 16; ++y) {
      for (uint8_t x = 0; x < 8; ++x) {
        if (gameMatrix_[y][x] > 0 and gameMatrix_[y][x] != FOOD_VALUE)
          gameMatrix_[y][x] -= 1;
      }
    }

    writeMatrixToFrame();
  }

  updateDisplay();
}

void Snake::restartGame() {
  gameOver_ = false;
  cycleCounter_ = 0;
  moveBuffer_ = UP;  //snake starts moving up
  snakeLength_ = 3;
  snakeHeadX_ = 3;
  snakeHeadY_ = 11;

  resetGameMatrix();

  //writes snake initial location
  gameMatrix_[snakeHeadY_][snakeHeadX_] = 3;
  gameMatrix_[snakeHeadY_ + 1][snakeHeadX_] = 2;
  gameMatrix_[snakeHeadY_ + 2][snakeHeadX_] = 1;
  placeFood();

  writeMatrixToFrame();  //resets frame buffer and writes snake position
  updateDisplay();
}