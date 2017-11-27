#include <iostream>
#include <string>
#include "instrument.h"

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


