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
  //std::cout << "SimpleSynth || process()" << std::endl;
  for (int i = 0; i < numSamples; i++) {
    outputBuffer[i] = oscPointer->getSample();
    oscPointer->tick();
  }
}

void SolfegeSynth::setWave(int waveType) {
    switch (waveType) {
        case 0:
          oscPointer = &sine;
          break;
        case 1:
          //oscPointer = &square;
          break;
    default:
      std::cout << "Error: " << waveType << " is not a valid waveform" << std::endl;
  }
}

void SolfegeSynth::updatePitch(){
    mtofConverter noteConverter;
    oscPointer->setFreq(noteConverter.mtof(getPitch()), getSampleRate());
}