/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Synthesizer.cpp
 * Author: nickverbeek
 * 
 * Created on 6 maart 2018, 9:20
 */

#include "Synthesizer.h"

Synthesizer::Synthesizer() {
}

Synthesizer::Synthesizer(const Synthesizer& orig) {
}

Synthesizer::~Synthesizer() {
}

void Synthesizer::setPitch(float pitch){
    this->pitch = pitch;
}

void Synthesizer::setSampleRate(int sampleRate){
    this->sampleRate = sampleRate;
}

float Synthesizer::getPitch(){
    return this->pitch;
}

int Synthesizer::getSampleRate(){
    return this->sampleRate;
}