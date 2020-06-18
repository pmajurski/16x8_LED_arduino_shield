// animation of an inch worm crawling around the edges of the screen
// animation updates every 35 refresh cycles

#ifndef INCH_WORM_H
#define INCH_WORM_H

#include "displayprocess.h"

class InchWorm : public DisplayProcess {
public:
    InchWorm();
    void init();
    void run(DirectionInput::MoveDirection input);

private:
    //indices of sprites in sprites_
    const uint8_t STRAIGHT = 0;
    const uint8_t CURLED = 1;
    const uint8_t ENTER_CORNER = 2;
    const uint8_t IN_CORNER = 3;
    const uint8_t EXIT_CORNER = 4;

    //changes worm state to next sprite in animation
    void moveTheWorm();
    //sprite update for standard non-corner moves
    void updateWormSprite();
    //changes wall. inch worm moves clockwise around the edge of the screen
    void switchWall();
    //checks if y and x arguments are out of bounds coordinates
    bool wormOutOfBounds(int8_t y, int8_t x);

    int8_t wormX_;  //x coordinate of worm [column]; top left corner of 4x4 bit grid
    int8_t wormY_;  //y coordinate of worm [row]
    int8_t wormDY_;  //delta y direction
    int8_t wormDX_;  //delta x direction
    DirectionInput::MoveDirection wall_;  //wall inch worm is on
    uint8_t sprites_[5][4];  //sprites for current wall
    uint8_t currentSprite_;  //current sprite displayed
};

#endif  //INCH_WORM_H
