/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Instrument.cpp
 * Author: nickverbeek
 * 
 * Created on 31 januari 2018, 16:37
 */

#include <iostream>
#include <string>
#include "Instrument.h"

Instrument::Instrument(std::string instrumentType, std::string instrumentSound){

	this->type=instrumentType;
	this->sound=instrumentSound;
}

void Instrument::playTone(){

	std::cout << "The " << type << " plays " << sound << std::endl;
}

void Instrument::playMultipleSounds(int num){
	this->plays=num;
	for (int i=0; i<num; i++){
		playTone();
	}
}

