// simple maze. Player controls a blinking cursor. Start in lower left corner, finish in upper right corner.
// game updates every 10 refresh cycles

#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include "displayprocess.h"

class MazeGame : public DisplayProcess {
public:
    MazeGame();
    void init();
    void run(DirectionInput::MoveDirection input);

private:
    //tests if y,x coordinate is in display area and not a maze wall
    bool isValidPosition(int8_t y, int8_t x);
    //updates and blinks cursor; moves with moveBuffer_
    void moveCursor();
    //draws and blinks cursor from frame buffer; updates display
    void drawCursor();
    void eraseCursor();
    void restartGame();

    //bounds and positions of start and finish
    const int8_t UPPER_Y_BOUND = 15;
    const int8_t UPPER_X_BOUND = 7;
    const int8_t START_Y = 15;
    const int8_t START_X = 0;
    const int8_t FINISH_Y = 0;
    const int8_t FINISH_X = 7;

    int8_t yPos_;  //cursor row
    int8_t xPos_;  //cursor column
    bool blinkState_;  //determines if player cursor on/off for refresh blink
    bool gameOver_;
};

#endif  //MAZE_GAME_H
