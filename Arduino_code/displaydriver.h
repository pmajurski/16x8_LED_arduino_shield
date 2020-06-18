// display driver for the MAX7219: 2 chips driving two 8x8 LED matrices
// board set up 16x8: upper matrix rows 0-7, lower matrix rows 8-15, row index increases downwards

#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H

#include "Arduino.h"
#include "SPI.h"

class DisplayDriver {
public:
    DisplayDriver();

    //4-bit (left aligned) intensity code from 0x00 -> 0x0F
    //16 intensity levels
    void increaseBrightness();
    void decreaseBrightness();

    //framebuffer size is 16; each index is row on display
    //rewrites entire display with frameBuffer; lower indexes are upper 8x8 matrix LEDs
    void updateDisplay(const uint8_t frameBuffer[16]);

    //sets every LED to off
    void clearDisplay();

    //sets shutdown state on MAX7219 to enable / disable display output
    void disableDisplay();
    void enableDisplay();

private:
    //relative pins for SPI
    const uint8_t CHIP_SELECT = 10;
    const uint8_t MASTEROUT_SLAVEIN = 11;
    const uint8_t MASTERIN_SLAVEOUT = 12;
    const uint8_t SERIAL_CLK = 13;

    //control register addresses for MAX7219
    const uint16_t INTENSITY_REG = 0x0A00;
    const uint16_t DISPLAY_TEST_REG = 0x0F00;

    //operation codes for MAX7219: control register addresses + command code
    const uint16_t SHUTDOWN_ENABLE = 0x0C00;
    const uint16_t SHUTDOWN_DISABLE = 0x0C01;
    const uint16_t NO_OP = 0x0000;
    const uint16_t SCAN_ALL = 0x0B07;

    //brightness adjustment step size
    const uint8_t INTENSITY_STEP_SIZE = 2;

    //default and extrema intensity values
    const uint8_t DEFAULT_INTENSITY = 0x00;
    const uint8_t MAX_INTENSITY = 0x0F;
    const uint8_t MIN_INTENSITY = 0x00;

    //disables the "display test" mode on the MAX2719 drivers
    void disableDisplayTest();

    //manually initializes pins for SPI to work around hardcoded SS active low in SPI library
    void configSPI();

    //sets scan line to all LEDs, default intensity, and disables shutdown mode
    void configDisplay();

    //transmits two 16-bit commands to the 2x MAX chips
    //spi data are always in pairs; numPackets is always even
    void spiTransmit(const uint16_t spiData[], uint8_t numPackets);

    uint8_t intensity_;  //display brightness
};




#endif //DISPLAYDRIVER_H