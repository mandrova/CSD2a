/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntervalTrainer.h
 * Author: nickverbeek
 *
 * Created on 26 februari 2018, 23:23
 */

#ifndef INTERVALTRAINER_H
#define INTERVALTRAINER_H

#include "AudioPlayer.h"

class IntervalTrainer {
public:
    IntervalTrainer();
    IntervalTrainer(const IntervalTrainer& orig);
    virtual ~IntervalTrainer();
    
    void showRules();
    void playNote(int midiNote);
    void stopNote();
    void askUserInterval();
    void checkUserInput(int userSelection);
    
private:
    int firstMidiNote;
    int secondMidiNote;
    int userSelection;
    AudioPlayer audio;
};

#endif /* INTERVALTRAINER_H */

