#include "displaydriver.h"

DisplayDriver::DisplayDriver() {
  intensity_ = DEFAULT_INTENSITY;
  configSPI();
  disableDisplayTest();  //prevents LED displays being placed into display test mode on uploading code to Arduino
  configDisplay();
  clearDisplay();
}

void DisplayDriver::configSPI() {
  //SPI.begin();

  //configures SPI pins
  pinMode(CHIP_SELECT, OUTPUT);
  pinMode(MASTEROUT_SLAVEIN, OUTPUT);
  pinMode(SERIAL_CLK, OUTPUT);
  digitalWrite(CHIP_SELECT, LOW);  //drives CHIP_SELECT (LOAD on MAX7219) low

}

void DisplayDriver::configDisplay() {
  //transmits op codes to set intensity, disable shutdown, set scan all digits
  uint16_t intensity = INTENSITY_REG + intensity_;
  uint16_t spiData[] = {intensity, intensity, SCAN_ALL, SCAN_ALL, SHUTDOWN_DISABLE, SHUTDOWN_DISABLE};
  spiTransmit(spiData, 6);
}

void DisplayDriver::disableDisplayTest() {
  uint16_t spiData[] = {DISPLAY_TEST_REG, DISPLAY_TEST_REG};  //normal operation code is opcode followed by all zeros
  spiTransmit(spiData, 2);
}

void DisplayDriver::increaseBrightness() {
  if (intensity_ + INTENSITY_STEP_SIZE < MAX_INTENSITY)  //prevents overflow
    intensity_ += INTENSITY_STEP_SIZE;
  else
    intensity_ = MAX_INTENSITY;

  uint16_t spiData[] = {INTENSITY_REG + intensity_, INTENSITY_REG + intensity_};
  spiTransmit(spiData, 2);
}

void DisplayDriver::decreaseBrightness() {
  if (intensity_ > INTENSITY_STEP_SIZE)  //prevents underflow
    intensity_ -= INTENSITY_STEP_SIZE;
  else
    intensity_ = MIN_INTENSITY;

  uint16_t spiData[] = {INTENSITY_REG + intensity_, INTENSITY_REG + intensity_};
  spiTransmit(spiData, 2);
}

void DisplayDriver::updateDisplay(const uint8_t frameBuffer[16]) {
  //framebuffer size is 16; each index is row on display
  //rewrites entire display with frameBuffer; lower indexes are upper 8x8 matrix LEDs

  //MAX7219 data is MSB format
  //rows 0-7 upper, rows 8-15 lower; send in pairs eg 0,8 1,9

  //DIG outputs sink current - cathode, row select. set up so DIG0 is top most row
  //SEG outputs source current - set up so SEG_DP is left most column, SEG_G rightmost
  //DATA IN - D7 -> D0; places right into register in same order

  //convert index in buffer into digit code for both displays in parallel
  //rows buffered in packets as: 0,8,1,9,2,10,3,11,4,12,5,13,6,14,7,15

  uint16_t spiData[16] = {0};  //data packets to update display. One per row
  uint16_t rowAddress = 0x0100;  //initial row address
  uint8_t bufferRow = 0;  //rows read in parallel from frameBuffer

  //iterates over frameBuffer sequentially reading bufferRow and bufferRow + 8 to program both displays at same time
  for (uint8_t i = 0; i < 16; i+=2) {
    spiData[i] = rowAddress + frameBuffer[bufferRow+8];  //second display (lower 8x8) first code in packet
    spiData[i+1] = rowAddress + frameBuffer[bufferRow];
    rowAddress += 0x0100;  //increments 'digit' register address
    bufferRow++;
  }

  spiTransmit(spiData, 16);  //send commands to MAX7219's
}

void DisplayDriver::clearDisplay() {
  uint16_t spiData[16] = {0};  //data packets to update display. One per row
  uint16_t rowAddress = 0x0100;  //initial row address in data packet

  for (uint8_t i = 0; i < 16; i+=2) {  //row address is in upper 8-bits. lower 8-bits are zero -> turn off row LEDs
    spiData[i] = rowAddress;
    spiData[i+1] = rowAddress;
    rowAddress += 0x0100;  //increments 'digit' register address
  }

  spiTransmit(spiData, 16);  //send commands to MAX7219's
}

void DisplayDriver::disableDisplay() {
  uint16_t spiData[] = {SHUTDOWN_ENABLE, SHUTDOWN_ENABLE};
  spiTransmit(spiData, 2);
}

void DisplayDriver::enableDisplay() {
  uint16_t spiData[] = {SHUTDOWN_DISABLE, SHUTDOWN_DISABLE};
  spiTransmit(spiData, 2);
}

void DisplayDriver::spiTransmit(const uint16_t spiData[], uint8_t numPackets) {
  //initializes SPI: max clock of 10MHz, most significant bit first, SPI mode 0
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));

  //transfers 2 commands to 2 MAX7219
  for (uint8_t i = 0; i < numPackets; i+=2) {
    SPI.transfer16(spiData[i]);
    SPI.transfer16(spiData[i+1]);

    //latches commands in MAX7219's
    digitalWrite(CHIP_SELECT, HIGH);
    digitalWrite(CHIP_SELECT, LOW);
  }

  SPI.endTransaction();
}




