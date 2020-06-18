// simple snake game. Only collisions with snake segments cause game over, screen boarders wrap around.
// Pressing up on game over screen restarts the game
// game updated every 20 refresh cycles

#ifndef SNAKE_H
#define SNAKE_H

#include "displayprocess.h"

class Snake : public DisplayProcess {
public:
    Snake();
    void init();
    void run(DirectionInput::MoveDirection input);

private:
    //places a piece of food randomly on the gameMatrix, has value foodValue_
    void placeFood();
    //updates snake position, snake moves every frame, does not reset move buffer
    void moveSnake();
    void restartGame();

    const uint8_t FOOD_VALUE = 0xFF;  //value of food position in gameMatrix
    uint8_t snakeLength_;  //length in pixels
    int8_t snakeHeadX_;  //x coordinate [column]
    int8_t snakeHeadY_;  //y coordinate [row]
    bool gameOver_;
};

#endif  //SNAKE_H
