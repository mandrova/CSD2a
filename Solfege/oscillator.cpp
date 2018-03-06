#include "oscillator.h"

Oscillator::Oscillator(){
    phase = 0;
    phaseStep = 0;
}

//Constructor and destructor
Oscillator::Oscillator(float freq){
    phase = 0;
    phaseStep = 0;
    
    setFreq(freq, this->sampleRate);
}

Oscillator::~Oscillator()
{

}

void Oscillator::tick()
{
  phase = fmod((phase + phaseStep), twoPi);
}

void Oscillator::setFreq(float freq, int sampleRate){
  this->freq = freq;
  this->sampleRate = sampleRate;

  std::cout << "freq: " << this->freq << ", Samplerate: " << this->sampleRate << std::endl;

  phaseStep = (twoPi / this->sampleRate) * this->freq;

  std::cout << "Oscillator || phaseStep = " << phaseStep << std::endl;
}