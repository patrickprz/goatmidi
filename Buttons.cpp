#include "Buttons.h"

int buttonState;  
int readingArray[6];
int lastButtonStateArray[6];
int lastDebounceTime = 0;   // the last time the output pin was toggled
int debounceDelay = 5;
bool ControlButtons [6];
uint8_t buttonsState [6];

Buttons::Buttons(){
    lastButtonStateArray[0] = HIGH;
    lastButtonStateArray[1] = HIGH;
    lastButtonStateArray[2] = HIGH;
    lastButtonStateArray[3] = HIGH;
    lastButtonStateArray[4] = HIGH;
    lastButtonStateArray[5] = HIGH;
}

void Buttons::ReadInputs(){
    readingArray[0] = digitalRead(SW1);
    readingArray[1] = digitalRead(SW2);
    readingArray[2] = digitalRead(SW3);
    readingArray[3] = digitalRead(SW4);
    readingArray[4] = digitalRead(SW5);
    readingArray[5] = digitalRead(SW6);

    for(int i; i < 6; i++){ 
      if (readingArray[i] != lastButtonStateArray[i]) {
          lastDebounceTime = millis();
      }
  
      if ((millis() - lastDebounceTime) > debounceDelay) {
          buttonState = readingArray[i];
          ControlButtons[i] = !readingArray[i];
      }
      lastButtonStateArray[i] = readingArray[i];
    }
}

uint8_t* Buttons::Engine(){
    ReadInputs();

    for (uint8_t i = 0; i < 6; i++)
    {
        if(buttonsState[i] == BUTTON_IDLE && ControlButtons[i] == true)
        {
            buttonsState[i] = BUTTON_PRESSED;
        }
        else if(buttonsState[i] == BUTTON_PRESSED && ControlButtons[i] == false)
        {
            buttonsState[i] = BUTTON_IDLE;
        }
        else if(buttonsState[i] == BUTTON_PRESSED && ControlButtons[i] == true)
        {
            buttonsState[i] = BUTTON_HOLDING;
        }
        else if (buttonsState[i] == BUTTON_HOLDING  && ControlButtons[i] == true)
        {
            buttonsState[i] = BUTTON_HOLDING;
        }
        else if (buttonsState[i] == BUTTON_HOLDING  && ControlButtons[i] == false)
        {
            buttonsState[i] = BUTTON_RELEASED;
        }
        else if(buttonsState[i] == BUTTON_RELEASED && ControlButtons[i] == false)
        {
            buttonsState[i] = BUTTON_IDLE;
        }else
        {
            buttonsState[i] = BUTTON_IDLE;
        }
    }
    return buttonsState;

}

Buttons buttons = Buttons();
