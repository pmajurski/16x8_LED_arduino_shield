# 16x8_LED_arduino_shield
16x8 LED display shield for Arduino Uno 


# Overview
This project is a custom shield for the Arduino Uno R3 and the controlling code. The display is two LuckyLight 8x8 LED matrices driven by two MAX7219 chips. Inputs for directional control, mode select, and brightness.
The display runs creatively named "display processes" which are relatively easy to create and add in. Display processes are broken up into animations and games. Animations can be static images, looping sequences of frames (ie gif), or animated sprites. Animations are non-interactive and ignore directional input. Games are interactive and use directional input.

# Controls
- Select toggles directional input between the current running process and mode select.
- Mode select: left / right cycles between animations, up / down cycles between games.
- Games are paused during mode select. Pressing select will unpause the active process. Animations ignore pause and will run during mode select.
- Brightness controls increase / decrease brightness. Default brightness can be adjusted in DisplayDriver.h

# Specs
- Display refresh and input polling at 50 Hz
- Powered by barrel jack connected to 9V battery. Optionally powered by Arduino Uno's barrel jack or USB.
- Display resolution of 16x8 pixels. Coordinate system is (y,x) with origin at top left corner. Y increases down, x increases right.
- Display draws roughly 340mA at full brightness.
 
# Creating new display processes
- Create a new child class of DisplayProcess
- Update animeProcesses or gameProcesses and their corresponding counts in .ino file.
- Display can be written to via a 16x8-bit frame buffer or 16x8-byte game matrix (which is then written to the frame buffer). 
- All processes share the frame buffer and game matrix.
- Sprites.cpp contains full frames stored in PROGMEM, which can be loaded directly into the frame buffer.

# Datasheets
- [MAX7219](https://www.sparkfun.com/datasheets/Components/General/COM-09622-MAX7219-MAX7221.pdf)
- [LuckyLight 8x8 LED matrix](https://cdn-shop.adafruit.com/datasheets/1820_KWM-R30881XPGB.pdf)

# Acknowledgements
- [forrestbao's kicad Arduino Uno shield footprint](https://github.com/forrestbao/arduino-kicad-library)
- [Adafruit Mini LED Gamer](https://github.com/adafruit/Adafruit_Learning_System_Guides/tree/master/Mini_LED_Gamer) - code for interrupt setup and modified snake game
- [MAX7219 driver wiring set up](https://playground.arduino.cc/Main/MAX72XXHardware/)