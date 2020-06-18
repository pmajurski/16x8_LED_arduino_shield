// abstract base class for all animations and game displayed. Display driver is created and controlled from this class.
// all display processes share a frame buffer, game matrix, and the display driver

#ifndef DISPLAYPROCESS_H
#define DISPLAYPROCESS_H

#include "Arduino.h"
#include <avr/pgmspace.h>  //enables reading from PROGMEM
#include "sprites.cpp"
#include "displaydriver.h"

namespace DirectionInput {  //namespace of move direction enum
    enum MoveDirection : uint8_t {
        NO_INPUT = 0,
        LEFT = 1,
        RIGHT = 2,
        UP = 3,
        DOWN = 4
    };
}


class DisplayProcess {
public:
    DisplayProcess(uint8_t cyclesPerFrame = 0);
    virtual void run(DirectionInput::MoveDirection input) = 0;
    virtual void init() = 0;

    static void increaseBrightness();
    static void decreaseBrightness();

    //pauses process. Animations ignore pause, play regardless
    void pause();
    void unpause();

protected:
    //sets every bit in frameBuffer to 0
    void resetFrameBuffer();

    //copies a 16x8 uint8_t frame from PROGMEM into frameBuffer
    void deepCopyFrame(const uint8_t *frame);

    //writes array of bytes to row column location. Permits negative rows that will be ignored but treated as start
    void writeToFrameBuffer(const uint8_t arr[4], int8_t row);

    //sets every element in gameMatrix to 0
    void resetGameMatrix();

    //validates game matrix row column coordinates
    bool inBounds(int8_t y, int8_t x);

    //overwrites frameBuffer with current state of gameMatrix. all non-zero elements in gameMatrix are converted into 1
    //all 0 elements are written as 0 in frameBuffer
    void writeMatrixToFrame();

    //writes frameBuffer to LED display
    void updateDisplay();

    static DisplayDriver display_;  //driver object frames are written to for display on LED matrix
    static uint8_t frameBuffer_[16];  //16x8-bit frame buffer shared by all display processes
    static uint8_t gameMatrix_[16][8];  //16x8-byte game board shared by all display processes

    bool isPaused_;  //determines if games will update during run; should follow state of selectMode for games
    DirectionInput::MoveDirection moveBuffer_;  //temp store for move command, held until next frame of a display process
    uint8_t cyclesPerFrame_;  //refresh cycles between each process update
    uint8_t cycleCounter_;  //counter for refresh cycles
};

#endif //DISPLAYPROCESS_H