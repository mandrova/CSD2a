/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.cpp
 * Author: nickverbeek
 * 
 * Created on 17 april 2018, 12:46
 */

#include <math.h>
#include "Delay.h"



unsigned long delayBuffer = 2048;
jack_default_audio_sample_t delaySamples[65536];
unsigned long delay = 65536;
unsigned long delayStep = 0;

Delay::Delay() : Effect(){
    setDelayTime(1024);//samples
    setDecayTime(0.6);//float
    setDryWetMix(0.5);
}

Delay::Delay(const Delay& orig) {
}

Delay::~Delay() {
}

void Delay::setDelayTime(int delayTime){
    this->delayTime = delayTime;
}

void Delay::setDecayTime(float decayTime){
    this->decayTime = decayTime;
}

void Delay::setFeedback(int feedback){
    this->feedback = feedback;
}

void Delay::setDryWetMix(float mix){
    this->mix = mix;
}

void Delay::process(JackModule jack){
    float *inBuffer = new float(delayBuffer);
    float *outBuffer = new float(delayBuffer);
    
    float *delayLine = new float(delayBuffer);
    
    do{
        jack.readSamples(inBuffer, delayBuffer);//read samples from jack
        for (unsigned int i = 0; i < delayBuffer; i++){
            //outBuffer[i] = delaySamples[delayStep]; Voorbeeld van Marc
            delayLine[i] = mix * ((inBuffer[i] * decayTime) + delaySamples[delayStep]);
            outBuffer[i] = inBuffer[i] + delayLine[i];
            delaySamples[delayStep]=inBuffer[i] + delayLine[i];//create delay
            delayStep++;
            delayStep %= delay;
        }//for
        jack.writeSamples(outBuffer,delayBuffer);
    }while(true);//do
}//process