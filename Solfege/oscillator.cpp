#include "oscillator.h"

Oscillator::Oscillator() : Oscillator(440, 44100){
    std::cout << "Hoofd Constructer van Oscillator" << std::endl;
}


//Constructor and destructor
Oscillator::Oscillator(float freq, int sampleRate){
    std::cout << "Child constructor van Oscillator met freq: " << freq << " en SampleRate: " << sampleRate << std::endl;
    phase = 0;
    phaseStep = 0;
    
    std::cout << "Oscilator after defining phase and phase step" << std::endl;
   
    
    setFreq(freq, sampleRate);
    std::cout << "Oscilator afster setFreq" << std::endl;
}

Oscillator::~Oscillator()
{

}

void Oscillator::tick()
{
  phase = fmod((phase + phaseStep), PI_2);
}

void Oscillator::setFreq(float freq, int sampleRate){
    std::cout << "begin setFreq from oscillator" << std::endl;
    this->freq = freq;
    this->sampleRate = sampleRate;
  
    std::cout << "after defining freq and sampleRate" << std::endl;

    std::cout << "freq: " << this->freq << ", Samplerate: " << this->sampleRate << std::endl;

    phaseStep = (PI_2 / this->sampleRate) * this->freq;

    std::cout << "Oscillator || phaseStep = " << phaseStep << std::endl;
    std::cout << "end of setFreq from oscillator" << std::endl;
}