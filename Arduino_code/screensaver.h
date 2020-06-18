// animation of a 2x2 pixel square bouncing around the screen, similar to classic screen savers
// animation updated every 35 refresh cycles

#ifndef SCREEN_SAVER_H
#define SCREEN_SAVER_H

#include "displayprocess.h"

class ScreenSaver : public DisplayProcess {
public:
    ScreenSaver();
    void init();
    void run(DirectionInput::MoveDirection input);

private:
    //updates game matrix for block. pixel state can be either 0 or 1, clearing or writing block sprite
    void updateBlockSprite(uint8_t pixelState);

    const int8_t UPPER_Y_BOUND = 14;
    const int8_t UPPER_X_BOUND = 6;
    int8_t yPos_;  //row of upper left corner of sprite
    int8_t xPos_;  //column of upper left corner of sprite
    int8_t dy_;  //direction of y movement
    int8_t dx_;  //direction of x movement
};

#endif  //SCREEN_SAVER_H
