/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mtofConverter.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:41
 */

#include "mtofConverter.h"
#include <stdio.h>
#include <math.h>

mtofConverter::mtofConverter() {
}

mtofConverter::mtofConverter(const mtofConverter& orig) {
}

mtofConverter::~mtofConverter() {
    
}

float mtofConverter::mtof(int midiNote){
    this->frequency = 440*(pow(2.0f, (((float)midiNote - 60)/12)));
    return this->frequency;
}
