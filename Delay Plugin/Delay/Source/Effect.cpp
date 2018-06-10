//
//  Effect.cpp
//  Delay
//
//  Created by Nick Verbeek on 04-05-18.
//

#include <stdio.h>
#include "Effect.h"

Effect::Effect(){
    
}

Effect::~Effect(){
    
}

//set input level
void Effect::setInputLevel(float inputLevel){
    this->inputLevel = inputLevel;
}

//set output level
void Effect::setOutputLevel(float outputLevel){
    this->outputLevel = outputLevel;
}

//get input level
float Effect::getInputLevel(){
    return inputLevel;
}

//get output level
float Effect::getOutputLevel(){
    return outputLevel;
}
