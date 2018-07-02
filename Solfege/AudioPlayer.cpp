/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioPlayer.cpp
 * Author: nickverbeek
 * 
 * Created on 27 februari 2018, 9:18
 */

#include "AudioPlayer.h"
#include <iostream>
#include <thread>
#include <unistd.h>

#include "jack_module.h"
#include "sine.h"
#include "mtofConverter.h"
#include "SolfegeSynth.h"


AudioPlayer::AudioPlayer() {
}

AudioPlayer::AudioPlayer(const AudioPlayer& orig) {
}

AudioPlayer::~AudioPlayer() {
}

//Play audio signal with the given frequency from a midinote
void AudioPlayer::playAudio(int firstMidiNote, int secondMidiNote){
    //create an instance of SolfegeSynth
    SolfegeSynth *synth = new SolfegeSynth();
    //std::cout << "synth is gemaakt" << std::endl;
    synth->setPitch(firstMidiNote);
    
    //create an jack instance
    JackModule jack;
    synth->setSampleRate(jack.getSamplerate());
    
    
    //assign a function to the JackModule::onProces    
    jack.onProcess = [&synth](jack_default_audio_sample_t *inBuf,
            jack_default_audio_sample_t *outBuf, jack_nframes_t nframes){
        synth->process(outBuf, nframes);
        return 0;
    };
    
    // init the jack, use program name as JACK client name
    jack.init("App");
    jack.autoConnect();
    
    //keep the program running and listen for user input
    this->running = true;
    //std::cout << "blabla" << std::endl;
    
    //std::cout << "djshfkhsjdhfjkskdhfjskjdfhs" << std::endl;
    
    while(running){
        //usleep(1000);
        //synth.setPitch(200);
        //synth.updatePitch();
        //std::cout << "hkjlghkjlgkhhrjekth" << std::endl;
        switch(std::cin.get()){
            case '1': running = false;
                break;
        }
    }

}

void AudioPlayer::stopRunning(){
    this->running = false;
}