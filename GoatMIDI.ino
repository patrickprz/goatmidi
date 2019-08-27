#include "Bluetooth.h"
#include "IO.h"

int incomingByte = 0;
String receivedData;

void setup() {
  Serial2.begin(9600);
  Serial2.println("GOAT MIDI CONTROLLER");
  pinMode(LED, OUTPUT);
}

void bluetoothHandle(){
  if (bluetooth.Available()) {
    receivedData = bluetooth.Read();
    bluetooth.SendData(receivedData);

    if(receivedData == "1"){
      digitalWrite(LED, LOW);
    }

    if(receivedData == "0"){
      digitalWrite(LED, HIGH);
    }
  }
}

void loop() {
  bluetoothHandle();
}
