// animation of a beating heart
// animation updates at variable interval
// small heart(50) - big heart(20) - small heart(20) - big heart(20) -> repeat

#ifndef BEATINGHEART_H
#define BEATINGHEART_H

#include "displayprocess.h"

class BeatingHeart : public DisplayProcess {
public:
    BeatingHeart();
    void run(DirectionInput::MoveDirection input);
    void init();

private:
    const uint8_t NUM_ANIMATION_FRAMES = 4;  //number of frames in animation loop
    uint8_t displayTimes_[4];  //time each frame is displayed, in refresh cycles
    uint8_t currentFrame_;  //current frame in animation
};

#endif  //BEATINGHEART_H
