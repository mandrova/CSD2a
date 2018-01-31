#ifndef _Trumpet_H_
#define _Trumpet_H_

#include <string>
#include "brass.h"

class Trumpet : public Brass{
public:
	Trumpet(std::string trumpetType);
	~Trumpet();
	std::string getRange();

private:
	std::string range = "F#3-D6";
	std::string sound = "BRaaaaaaaaaaaaaa!";
	std::string trumpetType = ""
	int xButtons = 0;

}