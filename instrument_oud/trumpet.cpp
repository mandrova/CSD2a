#include <iostream>
#include "trumpet.h"

Trumpet::Trumpet(std::string trumpetType) : brass(this->type, this->sound){
	this->trumpetType = trumpetType;
	std::cout << "Constructor van trumpet" << std::endl;
}

Trumpet::~Trumpet(){
	std::cout << "Destructor van trumpet" << std::endl;
}

std::string Trumpet::getRange(){
	return this->type;
}
