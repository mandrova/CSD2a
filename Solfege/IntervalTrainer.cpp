/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntervalTrainer.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:23
 */

#include <iostream>

#include "IntervalTrainer.h"
#include "IntervalGenerator.h"
#include "Interval.h"
#include "AudioPlayer.h"

IntervalTrainer::IntervalTrainer() {
}

IntervalTrainer::IntervalTrainer(const IntervalTrainer& orig) {
}

IntervalTrainer::~IntervalTrainer() {
}

void IntervalTrainer::showRules(){
    //top text
    std::cout << "-----------------------Rules-------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "A Interval will be generated. Every interval has two " << std::endl;
    std::cout << "notes. Wich will be played in serial. The interval \n"
            "can be replayed by typing 'play' and hit enter. By using\n"
            "the intervallist you can choose the right interval that \n"
            "has been played." << std::endl;
}

void IntervalTrainer::playNote(int midiNote){
    //audio.playAudio(midiNote);
}

void IntervalTrainer::stopNote(){
    //audio.stopRunning();
}

void IntervalTrainer::askUserInterval(){
    
}

void IntervalTrainer::checkUserInput(int userSelection){
    
}