/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strings.cpp
 * Author: nickverbeek
 * 
 * Created on 31 januari 2018, 17:15
 */

#include <iostream>
#include "Strings.h"
#include "Instrument.h"

Strings::Strings(int xStrings, std::string type, std::string sound) : Instrument(type, sound) {
    this->xSnares = xStrings;
    std::cout << "Constructor van Strings" << std::endl;
}

Strings::~Strings() {
    std::cout << "Deconstructor van Strings" << std::endl;
}

