/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Synthesizer.h
 * Author: nickverbeek
 *
 * Created on 6 maart 2018, 9:20
 */

#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

class Synthesizer{
public:
    Synthesizer();
    Synthesizer(const Synthesizer& orig);
    virtual ~Synthesizer();
    
    virtual void process(float *outputBuffer, int numSamples) = 0;
    void setPitch(float pitch);
    void setSampleRate(int sampleRate);
    float getPitch();
    int getSampleRate();
    virtual void updatePitch() = 0;
private:
    float pitch;
    int sampleRate;
};

#endif /* SYNTHESIZER_H */

