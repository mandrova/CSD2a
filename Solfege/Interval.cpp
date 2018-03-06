/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interval.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:31
 */

#include "Interval.h"

Interval::Interval() {
}

Interval::Interval(const Interval& orig) {
}

Interval::~Interval() {
}

void Interval::setInterval(int firstMidiNote, int secondMidiNote){
    this->firstMidiNote = firstMidiNote;
    this->secondMidiNote = secondMidiNote;
}

int Interval::getFirstNote(){
    return this->firstMidiNote;
}

int Interval::getSecondNote(){
    return this->secondMidiNote;
}