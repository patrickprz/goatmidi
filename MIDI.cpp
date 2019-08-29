#include "MIDI.h"

MIDI::MIDI()
{
  USBMIDI.begin();
  delay(1000);
}


void MIDI::SendCC(uint8_t cc){
  //chanel, note, intensity
  USBMIDI.sendControlChange(0,cc,127);
}

void MIDI::SendNote(uint8_t note){
  //channel, note, velocity
  USBMIDI.sendNoteOn(0, note, 80);
  delay(1000);
  USBMIDI.sendNoteOff(0, note, 80);
}

MIDI midi = MIDI();
