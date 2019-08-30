#ifndef LEDs_h
#define LEDs_h

#include "Arduino.h"
#include "IO.h"

class LEDs
{
  public:
    LEDs();
    void SetColor(uint16_t rValue, uint16_t gValue, uint16_t bValue);
};

extern LEDs leds;
#endif
