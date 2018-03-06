/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntervalGenerator.h
 * Author: nickverbeek
 *
 * Created on 26 februari 2018, 23:28
 */

#ifndef INTERVALGENERATOR_H
#define INTERVALGENERATOR_H

#include "Interval.h"

class IntervalGenerator {
public:
    IntervalGenerator();
    IntervalGenerator(const IntervalGenerator& orig);
    virtual ~IntervalGenerator();
    
    void generateInterval();
    int getFirstIntervalNote();
    int getSecondIntervalNote();
    int getAnswer();
private:
    Interval interval;
    int answer;
};

#endif /* INTERVALGENERATOR_H */

