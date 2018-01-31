/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Brass.cpp
 * Author: nickverbeek
 * 
 * Created on 31 januari 2018, 16:39
 */

#include <iostream>
#include <string>
#include "Brass.h"

Brass::Brass(std::string type, std::string sound) : Instrument(type, sound){
	std::cout << "Constructor van Brass" << std::endl;
}

Brass::~Brass(){
	std::cout << "Destructor van Brass" << std::endl;
}