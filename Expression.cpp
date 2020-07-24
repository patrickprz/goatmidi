#include "Expression.h"

int midiValue = 0; 
int raw = 0; 
int aux = 0;

Expression::Expression()
{

}

int Expression::Read(){
  delay(1);
  aux++;
  raw += analogRead(EXPRESSION_PIN);
  if(aux == 12){
    aux = 0;
    raw = raw/12;
    midiValue = map(raw, 0, 3700, 0, 127);
    if(midiValue > 127){
      midiValue = 127;
    }
    raw = 0;
  }
  return midiValue; 
}


Expression expression = Expression();
