#include "MIDI.h"

MIDI::MIDI()
{
  USBMIDI.begin();
  delay(1000);
}


void MIDI::SendCC(uint8_t cc){
  USBMIDI.sendControlChange(0,cc,127);
}

MIDI midi = MIDI();
