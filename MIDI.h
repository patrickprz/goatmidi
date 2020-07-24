/*
  Bluetooth jdy-19
*/

#ifndef MIDI_h
#define MIDI_h

#include "Arduino.h"
#include "IO.h"
#include <USBMIDI.h>

class MIDI
{
  public:
    MIDI();
    void SendCC(uint8_t cc);
    void SendNote(uint8_t note);
    void SendExpressionCC(uint8_t note, uint8_t val);
};

extern MIDI midi;
#endif
