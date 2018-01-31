/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strings.h
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 17:15
 */

#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include "Instrument.h"

class Strings : public Instrument{
public:
    Strings(int xSnares, std::string type, std::string sound);
    virtual ~Strings();
private:
    int xSnares;
};

#endif /* STRINGS_H */

