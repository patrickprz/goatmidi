/*
  Bluetooth jdy-19
*/

#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"
#include "IO.h"

class Bluetooth
{
  public:
    Bluetooth();
    bool Available();
    void SendData(String data);
    String Read();
};

extern Bluetooth bluetooth;
#endif
