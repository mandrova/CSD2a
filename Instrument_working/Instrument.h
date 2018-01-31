/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Instrument.h
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 16:37
 */

#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>

class Instrument{

public:
	Instrument(std::string instrumentType, std::string instrumentSound);
	void playTone();
	void playMultipleSounds(int num);

private:
	std::string type = "None";
	std::string sound = "None";
	int plays = 0;
};

#endif /* INSTRUMENT_H */

