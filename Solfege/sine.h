#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"

class Sine : public Oscillator
{
public:

  //constructors and destructor
  Sine();
  ~Sine();

  float getSample() override;
};

#endif
