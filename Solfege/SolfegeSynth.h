/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SolfegeSynth.h
 * Author: nickverbeek
 *
 * Created on 6 maart 2018, 9:28
 */

#ifndef SOLFEGESYNTH_H
#define SOLFEGESYNTH_H

#include "Synthesizer.h"
#include "oscillator.h"
#include "sine.h"


class SolfegeSynth : public Synthesizer{
public:
    SolfegeSynth();
    SolfegeSynth(const SolfegeSynth& orig);
    virtual ~SolfegeSynth();
    
    void process(float *outputBuffer, int numSamples) override;
    void setWave(int waveType);
    void updatePitch() override;
private:
    Oscillator *oscPointer;
    Sine sine;
};

#endif /* SOLFEGESYNTH_H */

