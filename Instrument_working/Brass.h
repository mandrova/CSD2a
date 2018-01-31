/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Brass.h
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 16:39
 */

#ifndef BRASS_H
#define BRASS_H

#include <string>
#include "Instrument.h"

class Brass : public Instrument{
public:
	Brass(std::string type, std::string sound);
	~Brass();
	std::string getInstrumentType();

private:
	std::string type="Brass";

};

#endif /* BRASS_H */

