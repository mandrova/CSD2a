/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trumpet.h
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 16:41
 */

#ifndef TRUMPET_H
#define TRUMPET_H

#include <string>
#include "Brass.h"

class Trumpet : public Brass{
public:
	Trumpet(std::string trumpetType, std::string type, std::string sound);
	~Trumpet();
	std::string getRange();

private:
	std::string range = "F#3-D6";
	std::string sound = "BRaaaaaaaaaaaaaa!";
        std::string type = "Brass";
	std::string trumpetType = "";
	int xButtons = 3;

};

#endif /* TRUMPET_H */

