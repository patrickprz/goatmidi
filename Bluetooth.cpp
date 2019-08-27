#include "Arduino.h"
#include "Bluetooth.h"

Bluetooth::Bluetooth()
{
}

bool Bluetooth::Available(){
  if (Serial2.available() > 0) {
    return true;  
  }
  return false;
}

void Bluetooth::SendData(String data){
  Serial2.print(data);
}

String Bluetooth::Read(){
  String content = "";
  char data;
  
  while(Serial2.available() > 0) {
    data = Serial2.read();

    if (data != '\r' && data != '\n'){
      content.concat(data);
    }
    delay(10);
  }
 
  return content;
}

Bluetooth bluetooth = Bluetooth();
