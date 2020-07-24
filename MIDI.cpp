#include "MIDI.h"

USBMIDI _midi;

MIDI::MIDI()
{
  _midi.begin();
  delay(1000);
}


void MIDI::SendCC(uint8_t cc){
  //chanel, note, intensity
  _midi.sendControlChange(0,cc,127);
}

void MIDI::SendExpressionCC(uint8_t cc, uint8_t val){
  //chanel, note, intensity
  _midi.sendControlChange(0,cc,val);
}

void MIDI::SendNote(uint8_t note){
  //channel, note, velocity
  _midi.sendNoteOn(0, note, 80);
  delay(1000);
  _midi.sendNoteOff(0, note, 80);
}

MIDI midi = MIDI();
