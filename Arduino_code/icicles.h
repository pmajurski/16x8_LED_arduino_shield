// animation of icicles dripping pixels
// animation updates every 3 refresh cycles

#ifndef ICICLES_H
#define ICICLES_H

#include "displayprocess.h"

class Icicles : public DisplayProcess {
public:
    Icicles();
    void run(DirectionInput::MoveDirection input);
    void init();

private:
    //moves falling drips one row down
    void dripPixel(uint8_t index);

    uint8_t dripColumn_[4];  //columns [x coordinates]
    uint8_t dripRow_[4];  //row position of current drip
};

#endif  //ICICLES_H
