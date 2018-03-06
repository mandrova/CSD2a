#include "sine.h"

// Constructor/Destructor
Sine::Sine() : Oscillator() {
  std::cout << "SineWave || constructor" << std::endl;
}//SineWave()

Sine::~Sine() {
  std::cout << "SineWave || destructor" << std::endl;
}//~SineWave()



//Functions

float Sine::getSample() {
  //std::cout << "SineWave || getSample()" << std::endl;
  return sin(phase);
}//getSample()