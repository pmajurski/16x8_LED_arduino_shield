// animation of steam pixels rising from a mug
// animation updates every 50 refresh cycles

#ifndef MUG_WITH_STEAM_H
#define MUG_WITH_STEAM_H

#include "displayprocess.h"

class MugWithSteam : public DisplayProcess {
public:
    MugWithSteam();
    void init();
    void run(DirectionInput::MoveDirection input);
private:
    uint8_t prevPixelSpawn;  //position of last steam pixel spawn
};

#endif  //MUG_WITH_STEAM_H
