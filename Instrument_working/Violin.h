/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Violin.h
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 17:21
 */

#ifndef VIOLIN_H
#define VIOLIN_H

#include <iostream>
#include "Strings.h"

class Violin : public Strings{
public:
    Violin(int xStrings, std::string type, std::string sound);
    virtual ~Violin();
private:

};

#endif /* VIOLIN_H */

