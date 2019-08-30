#include "IO.h"
#include "LEDs.h"
#include "MIDI.h"
#include "Buttons.h"
#include "Bluetooth.h"

String receivedData;
uint8_t* buttonArray;

uint8_t red;
uint8_t green;
uint8_t blue;

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
  digitalWrite(LED, HIGH);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  red = 0;
  green = 0;
  blue = 0;
  
  leds.SetColor(red,green,blue);
}

void bluetoothHandle(){
  if (bluetooth.Available()) {
    receivedData = bluetooth.Read();
    //bluetooth.SendData(receivedData);

    if(receivedData == "LED:ON"){
      digitalWrite(LED, LOW);
    }

    if(receivedData == "LED:OFF"){
      digitalWrite(LED, HIGH);
    }

    if(receivedData.substring(0,6) == "SENDCC"){
      bluetooth.SendData(receivedData.substring(6, sizeof(receivedData)));
      midi.SendCC(receivedData.substring(6, sizeof(receivedData)).toInt());
    }

    if(receivedData.substring(0,8) == "SENDNOTE"){
      bluetooth.SendData(receivedData.substring(8, sizeof(receivedData)));
      midi.SendNote(receivedData.substring(8, sizeof(receivedData)).toInt());
    }

    if(receivedData.substring(0,5) == "COLOR"){
      bluetooth.SendData(receivedData.substring(5, 8));
      bluetooth.SendData(receivedData.substring(8, 11));
      bluetooth.SendData(receivedData.substring(11, 14));

      red = (uint8_t)receivedData.substring(5, 8).toInt();
      green = (uint8_t)receivedData.substring(8, 11).toInt();
      blue = (uint8_t)receivedData.substring(11, 14).toInt();
      
      leds.SetColor(red,green,blue);
    }
  }
}

void buttonHandle(){
  buttonArray = buttons.Engine();
  
  if(buttonArray[0] == Buttons::BUTTON_PRESSED){
    midi.SendCC(1);
    bluetooth.SendData("sw 1\n");
  }
  
  if(buttonArray[1] == Buttons::BUTTON_PRESSED){
    midi.SendCC(2);
    bluetooth.SendData("sw 2\n");
  }

  if(buttonArray[2] == Buttons::BUTTON_PRESSED){
    midi.SendCC(3);
    bluetooth.SendData("sw 3\n");
  }
  
  if(buttonArray[3] == Buttons::BUTTON_PRESSED){
    midi.SendCC(4);
    bluetooth.SendData("sw 4\n");
  }
  
  if(buttonArray[4] == Buttons::BUTTON_PRESSED){
    midi.SendCC(5);
    bluetooth.SendData("sw 5\n");
  }
  
  if(buttonArray[5] == Buttons::BUTTON_PRESSED){
    midi.SendCC(6);
    bluetooth.SendData("sw 6\n");
  }
}

void loop() {
  bluetoothHandle();
  buttonHandle();  


//  leds.Test(255,255,255);
//  delay(delayTime);
//  leds.Test(255,0,0);
//  delay(delayTime);
//  leds.Test(0,255,0);
//  delay(delayTime);
//  leds.Test(0,0,255);
//  delay(delayTime);
//  leds.Test(255,255,0);
//  delay(delayTime);
//  leds.Test(255,0,255);
//  delay(delayTime);
//  leds.Test(0,255,255);
//  delay(delayTime);
//  leds.Test(255,0,255);
//  delay(delayTime);
  
}
