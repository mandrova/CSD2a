/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trumpet.cpp
 * Author: nickverbeek
 * 
 * Created on 31 januari 2018, 16:41
 */

#include <iostream>
#include "Trumpet.h"

Trumpet::Trumpet(std::string trumpetType, std::string type, std::string sound) : Brass(type, sound){
	this->trumpetType = trumpetType;
	std::cout << "Constructor van trumpet" << std::endl;
}

Trumpet::~Trumpet(){
	std::cout << "Destructor van trumpet" << std::endl;
}

std::string Trumpet::getRange(){
	return this->range;
}

