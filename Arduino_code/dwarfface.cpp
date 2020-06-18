#include "dwarfface.h"
DwarfFace::DwarfFace() : DisplayProcess() {}

void DwarfFace::init() {
  deepCopyFrame(dwarfFace);
  updateDisplay();
}

void DwarfFace::run(DirectionInput::MoveDirection input) {}