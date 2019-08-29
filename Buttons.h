/*
  Buttons logic
*/

#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"
#include "IO.h"

class Buttons
{
  public:
    Buttons();
    void ReadInputs();
    uint8_t* Engine();

    enum STATE{
        BUTTON_IDLE,
        BUTTON_PRESSED,
        BUTTON_HOLDING,
        BUTTON_RELEASED,
    };
};

extern Buttons buttons;
#endif
