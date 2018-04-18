/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Effect.cpp
 * Author: nickverbeek
 * 
 * Created on 16 april 2018, 14:15
 */

#include "Effect.h"

Effect::Effect() {

}

Effect::Effect(const Effect& orig) {
}

Effect::~Effect() {
}

void Effect::setEffect(int effectType){
    switch(effectType){
        case 1://hier komt Delay
            break;
        case 2://hier komt Chorus
            break;
        case 3://hier komt Flanger
            break;
    }
}

void Effect::setMaxSamplesDelay(int maxSamplesDelay){
    this->maxSamplesDelay = maxSamplesDelay;
}

int Effect::getMaxSamplesDelay(){
    return this->maxSamplesDelay;
}