#include "Buttons.h"
#include "Bluetooth.h"
#include "IO.h"

String receivedData;
uint8_t* buttonArray;

void setup() {
  Serial2.begin(9600);
  Serial2.println("GOAT MIDI CONTROLLER");

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(SW6, INPUT_PULLUP);

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

void buttonHandle(){
  buttonArray = buttons.Engine();
  
  if(buttonArray[0] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 1\n");
  }
  
  if(buttonArray[1] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 2\n");
  }

  
  if(buttonArray[2] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 3\n");
  }
  
  if(buttonArray[3] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 4\n");
  }
  
  if(buttonArray[4] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 5\n");
  }
  
  if(buttonArray[5] == Buttons::BUTTON_PRESSED){
    bluetooth.SendData("sw 6\n");
  }
}

void loop() {
  bluetoothHandle();
  buttonHandle();  
}
