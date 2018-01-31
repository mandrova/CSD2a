

#include <string>

class Instrument{

public:
	Instrument(std::string type, std::string sound);
	void playTone();
	void playMultipleSounds(int num);

private:
	std::string type = "None";
	std::string sound = "None";
	int plays = 0;
};