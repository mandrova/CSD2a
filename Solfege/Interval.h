/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interval.h
 * Author: nickverbeek
 *
 * Created on 26 februari 2018, 23:31
 */

#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
public:
    Interval();
    Interval(const Interval& orig);
    virtual ~Interval();
    
    void setInterval(int firstMidiNote, int secondMidiNote);
    int getFirstNote();
    int getSecondNote();
    
private:
    int firstMidiNote;
    int secondMidiNote;
};

#endif /* INTERVAL_H */

