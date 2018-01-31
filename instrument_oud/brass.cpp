#include <iostream>
#include <string>
#include "brass.h"

Brass::Brass(std::string type, std::string sound) : Instrument(type, sound){
	std::cout << "Constructor van Brass" << std::endl;
}

Brass::~Brass(){
	std::cout << "Destructor van Brass" << std::endl;
}

