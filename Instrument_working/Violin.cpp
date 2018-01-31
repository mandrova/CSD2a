/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Violin.cpp
 * Author: nickverbeek
 * 
 * Created on 31 januari 2018, 17:21
 */

#include <iostream>
#include "Violin.h"

Violin::Violin(int xStrings, std::string type, std::string sound) : Strings(xStrings, type, sound) {
    std::cout << "Constructor van Strings" << std::endl;
}

Violin::~Violin() {
    std::cout << "Deconstructor van Strings" << std::endl;
}

