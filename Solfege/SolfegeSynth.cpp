/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SolfegeSynth.cpp
 * Author: nickverbeek
 * 
 * Created on 6 maart 2018, 9:28
 */

#include "SolfegeSynth.h"
#include "mtofConverter.h"

SolfegeSynth::SolfegeSynth() {
}

SolfegeSynth::SolfegeSynth(const SolfegeSynth& orig) {
}

SolfegeSynth::~SolfegeSynth() {
}

void SolfegeSynth::process(float *outputBuffer, int numSamples){
  for (int i = 0; i < numSamples; i++) {
    outputBuffer[i] = oscPointer->getSample();
    oscPointer->tick();
    //std::cout << "i = " << i << "numSamples: " << numSamples << std::endl;
  }
}

void SolfegeSynth::setWave(int waveType) {
    switch (waveType) {
        case 0:
          oscPointer = &sine; //assign sinewave to oscPointer
          break;
        case 1:
          //oscPointer = &square;
          break;
    default:
      std::cout << "Error: " << waveType << " is not a valid waveform" << std::endl;
  }
}

void SolfegeSynth::updatePitch(){
    //create an instance for mtofConverter
    mtofConverter noteConverter;
    oscPointer->setFreq(getPitch(), getSampleRate());
}