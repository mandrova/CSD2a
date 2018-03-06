/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   square.h
 * Author: nickverbeek
 *
 * Created on 27 februari 2018, 9:22
 */

#ifndef SQUARE_H
#define SQUARE_H

class square : Oscillator {
public:
      //constructors and destructor
  Square(double samplerate);
  Square(double samplerate, double frequency);
  Square(double samplerate, double frequency, double phase);
  ~Square();
  //prevent the default constructor to be generated
  Square() = delete;

  //override calculate
  //this method contains the sample calculation
  void calculate();
private:

};

#endif /* SQUARE_H */

