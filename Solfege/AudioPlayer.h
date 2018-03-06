/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioPlayer.h
 * Author: nickverbeek
 *
 * Created on 27 februari 2018, 9:18
 */

#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "jack_module.h"
#include "oscillator.h"
#include "sine.h"

class AudioPlayer {
public:
    AudioPlayer();
    AudioPlayer(const AudioPlayer& orig);
    virtual ~AudioPlayer();
    
    void playAudio(int firstMidiNote, int secondMidiNote);
    void stopRunning();
private:
    bool running;
    //Sine sine;
};

#endif /* AUDIOPLAYER_H */

