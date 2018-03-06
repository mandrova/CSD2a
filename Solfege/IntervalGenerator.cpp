/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntervalGenerator.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:28
 */

#include "IntervalGenerator.h"
#include "Interval.h"
#include <vector>
#include <stdlib.h>

//Interval interval;

IntervalGenerator::IntervalGenerator() {
    
}

IntervalGenerator::IntervalGenerator(const IntervalGenerator& orig) {
}

IntervalGenerator::~IntervalGenerator() {
}

void IntervalGenerator::generateInterval(){
        
    int firstNote;
    int secondNote;
    int randomInt;
    
    randomInt = rand() % 8 + 1;//generate a random value between 1 and 8
    this->answer = randomInt;//save answer
    
    firstNote = 60;
    
    switch(randomInt){
        case 1: secondNote = firstNote + 0;//c
            break;
        case 2: secondNote = firstNote + 2;//d
            break;
        case 3: secondNote = firstNote + 4;//e
            break;
        case 4: secondNote = firstNote + 5;//f
            break;
        case 5: secondNote = firstNote + 7;//g
            break;
        case 6: secondNote = firstNote + 9;//a
            break;
        case 7: secondNote = firstNote + 11;//b
            break;
        case 8: secondNote = firstNote + 12;//c octave
            break;
    }
    
    interval.setInterval(firstNote, secondNote);//set interval
    
}

int IntervalGenerator::getFirstIntervalNote(){
    return interval.getFirstNote();
}

int IntervalGenerator::getSecondIntervalNote(){
    return interval.getSecondNote();
}

int IntervalGenerator::getAnswer(){
    return this->answer;
}