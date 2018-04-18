/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Delay.h
 * Author: nickverbeek
 *
 * Created on 17 april 2018, 12:46
 */


#ifndef DELAY_H
#define DELAY_H

#include "Effect.h"
#include "jack_module.h"

class Delay: public Effect {
public:
    Delay();
    Delay(const Delay& orig);
    virtual ~Delay();
    
    void setDelayTime(int delayTime);
    void setDecayTime(float decayTime);
    void setFeedback(int feedback);
    void setDryWetMix(float mix);
    
    void process(JackModule);
    
private:
    int delayTime;
    float decayTime;
    int feedback;
    float mix;
    
    jack_default_audio_sample_t delaySamples[];
    unsigned long delay;
};

#endif /* DELAY_H */

