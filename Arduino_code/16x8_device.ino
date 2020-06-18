#include "Arduino.h"
#include "displayprocess.h"
#include "beatingheart.h"
#include "snake.h"
#include "mazegame.h"
#include "mugwithsteam.h"
#include "inchworm.h"
#include "icicles.h"
#include "screensaver.h"
#include "dwarfface.h"

using namespace DirectionInput;  //enum namespace for DisplayProcess move inputs

//defines pin numbers for input signals
enum InputSignal: uint8_t {
    SELECT_BUTTON = 3,
    LEFT_BUTTON = 4,
    RIGHT_BUTTON = 5,
    UP_BUTTON = 6,
    DOWN_BUTTON = 7,
    INCREASE_BRIGHTNESS = 8,
    DECREASE_BRIGHTNESS = 9,
    NO_SIGNAL = 255  //pin number 255 does not exist, used as no input
};

const uint8_t NUM_INPUTS = 7;  //number input pins used
const InputSignal INPUT_PINS[] = {
        SELECT_BUTTON,
        LEFT_BUTTON,
        RIGHT_BUTTON,
        UP_BUTTON,
        DOWN_BUTTON,
        INCREASE_BRIGHTNESS,
        DECREASE_BRIGHTNESS
};

//definite debounce and input cooldown
const uint8_t INPUT_COOLDOWN_CYCLES = 5;  //in refresh cycles - 5 = 100ms
const uint8_t DEBOUNCE_DELAY = 3;  //debounce minimum cycles for active state to count as valid input signal

//display processes available; MINIMUM of one of each process
DisplayProcess *gameProcesses[] = {
        new Snake(),
        new MazeGame()
};
DisplayProcess *animeProcesses[] = {
        new MugWithSteam(),
        new InchWorm(),
        new BeatingHeart(),
        new Icicles(),
        new ScreenSaver(),
        new DwarfFace()
};

const uint8_t NUM_GAMES = 2;
const uint8_t NUM_ANIMES = 6;
const uint8_t INITAL_ANIME = 5;  //index of anime process loaded on power up

uint8_t currentGame = 0;  //game process active or last active when in anime process
uint8_t currentAnime = INITAL_ANIME;  //anime process active or last active when in game process
DisplayProcess *activeProcess = animeProcesses[currentAnime];  //boots into an animation

//ISR volatile variables
volatile bool refreshDisplay = false;
volatile bool modeSelect = false;

//input handler variables
volatile uint8_t buttonHoldTimes[NUM_INPUTS] = {0};  //corresponds to elements of INPUT_PINS
volatile InputSignal inputBuffer = NO_SIGNAL;
volatile uint8_t inputCooldown = 0;

//enum type used for input directions in display processes
MoveDirection moveDirection = NO_INPUT;


//function prototypes
void inputHandler();  //iterates over signal pins looking for active pins
void processButton(uint8_t pinIndex);  //reads pins and debounces
void switchProcess();  //changes active display process
uint8_t getProcessIndex(uint8_t size, uint8_t index, bool direction);  //finds next display process
void setup();
void loop();


//50Hz timer interrupt for refreshing display
ISR(TIMER1_OVF_vect) {
  inputHandler();  //reads input signals. Buffers valid debounced inputs
  refreshDisplay = true;  //next loop() display process updates
}

void inputHandler() {
  inputBuffer = NO_SIGNAL;

  if (inputCooldown == 0) {  //cooldown since last input has expired; new input is accepted
    for (uint8_t i = 0; i < NUM_INPUTS; ++i) {  //read current button states; iterates over INPUT_PINS
      processButton(i);  //reads, debounces input signal

      if (inputBuffer != NO_SIGNAL)  //exits input handler if signal is valid
        return;
    }
  }
  else {  //cooldown between button presses is not over
    inputCooldown--;
  }
}

void processButton(uint8_t pinIndex) {
  if (digitalRead(INPUT_PINS[pinIndex]) == LOW) {  //determines if input is active
    buttonHoldTimes[pinIndex]++;

    if (buttonHoldTimes[pinIndex] > DEBOUNCE_DELAY) {  //signal active for longer than debounce period
      inputBuffer = INPUT_PINS[pinIndex];
      inputCooldown = INPUT_COOLDOWN_CYCLES;

      for (uint8_t j = 0; j < NUM_INPUTS; ++j)  //resets button hold times
        buttonHoldTimes[j] = 0;
    }
  }
  else {  //input signal is inactive, button hold time is reset
    buttonHoldTimes[pinIndex] = 0;
  }
}

void switchProcess() {
  switch (moveDirection) {  //computes next process index and updates activeProcess
    case LEFT:  //previous anime
      currentAnime = getProcessIndex(NUM_ANIMES, currentAnime, 0);
      activeProcess = animeProcesses[currentAnime];
      break;
    case RIGHT:  //next anime
      currentAnime = getProcessIndex(NUM_ANIMES, currentAnime, 1);
      activeProcess = animeProcesses[currentAnime];
      break;
    case UP:  //next game
      currentGame = getProcessIndex(NUM_GAMES, currentGame, 1);
      activeProcess = gameProcesses[currentGame];
      break;
    case DOWN:  //previous game
      currentGame = getProcessIndex(NUM_GAMES, currentGame, 0);
      activeProcess = gameProcesses[currentGame];
  }

  activeProcess->init();  //init new process
}

uint8_t getProcessIndex(uint8_t size, uint8_t index, bool direction) {
  //returns new index; handles wrap around logic
  //direction: 1-increments; 0-decrements
  if (direction) {  //forward move
    if (index < size - 1)
      return ++index;
    return 0;  //wraps around to beginning of array
  }
  else {  //backwards move
    if (index != 0)
      return --index;
    return (size - 1);  //wraps around to end of array
  }
}

void setup() {
  //configures all input pins as active low with internal pullup
  for (uint8_t i = 0; i < NUM_INPUTS; ++i)
    pinMode(INPUT_PINS[i], INPUT_PULLUP);

  randomSeed(analogRead(5));  //seeds random generation with unconnected pin
  for (uint8_t i = 0; i < 4; ++i) //skips first randoms, always same
    random();


  // taken from https://github.com/adafruit/Adafruit_Learning_System_Guides/blob/master/Mini_LED_Gamer/
  // ADC clock configurations
  byte ADPS_32 = _BV(ADPS2)|_BV(ADPS0);
  byte ADPS_128 = _BV(ADPS2)|_BV(ADPS1)|_BV(ADPS0);

  //ADC: 16MHz/16=1MHz
  ADCSRA &= ~ADPS_128;              // clean out ADPS
  ADCSRA |= ADPS_32;                // set Division Factor

  // Timer1 overflow interrupt setup
  TCNT1 = 0;                        // reset the counter
  ICR1 = 19999;                     // top value of the counter (16*10^6Hz/2000000*20000us/8-1) -> 1/20000us = 50Hz
  TCCR1A = 0;                       // clear TCCR1A (not used)
  TCCR1B = _BV(WGM13) | _BV(CS11);  // mode 8(PWM), set prescalar=8;
  TIMSK1 = _BV(TOIE1);              // Enable Overflow Interrupt


  activeProcess->init();  //start first display process
}

void loop() {
  if (refreshDisplay) {
    moveDirection = NO_INPUT;

    //interprets input signal
    switch (inputBuffer) {  //only 1 input signal can be generated at a time
      case SELECT_BUTTON:
        if (modeSelect)  //leaving mode select
          activeProcess->unpause();
        else  //entering mode select
          activeProcess->pause();
        modeSelect = !modeSelect;  //switches how directional input is handled
        break;
      case INCREASE_BRIGHTNESS:
        DisplayProcess::increaseBrightness();
        break;
      case DECREASE_BRIGHTNESS:
        DisplayProcess::decreaseBrightness();
        break;
      case LEFT_BUTTON:
        moveDirection = LEFT;
        break;
      case RIGHT_BUTTON:
        moveDirection = RIGHT;
        break;
      case UP_BUTTON:
        moveDirection = UP;
        break;
      case DOWN_BUTTON:
        moveDirection = DOWN;
    }

    //direction input is handled differently in mode select. the current display process is changed and init
    if (modeSelect and moveDirection != NO_INPUT)
      switchProcess();  //changes active process
    else
      activeProcess->run(moveDirection);  //updates process, stepping one frame

    refreshDisplay = false;
  }
}






