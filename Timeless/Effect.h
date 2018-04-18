/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Effect.h
 * Author: nickverbeek
 *
 * Created on 16 april 2018, 14:15
 */

#ifndef EFFECT_H
#define EFFECT_H

class Effect {
public:
    Effect();
    Effect(const Effect& orig);
    virtual ~Effect();
    
    void setEffect(int);
    void setMaxSamplesDelay(int);
    int getMaxSamplesDelay();
    
private:
    int maxSamplesDelay;
    
};

#endif /* EFFECT_H */

