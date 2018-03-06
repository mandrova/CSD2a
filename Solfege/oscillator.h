#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
#include <cmath>

#define PI_2 6.28318530717959

class Oscillator
{
public:
  Oscillator();
  Oscillator(float freq);
  ~Oscillator();

  virtual float getSample() = 0;
  void tick();

  void setFreq(float freq, int sampleRate);

  //NOTE - do we need a setter for phase? for now -> not using one


protected:
  double phase;
  double phaseStep;

private:
  float freq;
  int sampleRate;
  static constexpr double twoPi = 2 * 3.14159265358979323846;



};

#endif
