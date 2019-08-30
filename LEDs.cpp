#include "LEDs.h"
uint8_t R;
uint8_t G;
uint8_t B;

LEDs::LEDs()
{
  
}

void LEDs::SetColor(uint16_t rValue, uint16_t gValue, uint16_t bValue){
  rValue = 255 - ((126*rValue)/255);
  gValue = 255 - ((240*gValue)/255);
  bValue = 255 - bValue;
  
  R = (uint8_t)rValue;  
  G = (uint8_t)gValue;
  B = (uint8_t)bValue;

  analogWrite(LED_R, R);
  analogWrite(LED_G, G);
  analogWrite(LED_B, B);
}

LEDs leds = LEDs();
