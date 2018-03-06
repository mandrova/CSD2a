/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mtofConverter.h
 * Author: nickverbeek
 *
 * Created on 26 februari 2018, 23:41
 */

#ifndef MTOFCONVERTER_H
#define MTOFCONVERTER_H

class mtofConverter {
public:
    mtofConverter();
    mtofConverter(const mtofConverter& orig);
    virtual ~mtofConverter();
    
    float mtof(int midiNote);
    
private:
    double frequency;
};

#endif /* MTOFCONVERTER_H */

