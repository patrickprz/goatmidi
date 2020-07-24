#ifndef Expression_h
#define Expression_h

#include "Arduino.h"
#include "IO.h"

class Expression
{
  public:
    Expression();
    int Read();
};

extern Expression expression;
#endif
