// static image of a dwarf face
#ifndef DWARF_FACE_H
#define DWARF_FACE_H

#include "displayprocess.h"

class DwarfFace : public DisplayProcess {
public:
    DwarfFace();
    void init();
    void run(DirectionInput::MoveDirection input);
};

#endif  //DWARF_FACE_H