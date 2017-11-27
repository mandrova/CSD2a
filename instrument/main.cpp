#include <string>
#include <iostream>
#include "instrument.h"

int main(int argc, char **argv){

	Instrument piano("Piano", "Dang");
	std::cout << "-----------------------------" << std::endl;
	std::cout << "------playTone Functie-------" << std::endl;
	piano.playTone();

	std::cout << "-----------------------------" << std::endl;
	std::cout << "--playMultipleSounds Functie--" << std::endl;

	piano.playMultipleSounds(10);

	return 0;
}