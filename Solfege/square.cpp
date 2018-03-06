/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   square.cpp
 * Author: nickverbeek
 * 
 * Created on 27 februari 2018, 9:22
 */

#include "square.h"
#include "oscillator.h"


//Constructors and destructor
square::Square(double samplerate) : square(samplerate, 0, 0) {}

square::Square(double samplerate, double frequency) :
  Sine(samplerate, frequency, 0) {}

square::Square(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

square::~Square() {}

//override calculate method
//this method contains the sample calculation
void square::calculate()
{
  //NOTE sin() method is not the most efficient way to calculate the sine value
  sample = sin(phase * PI_2 );
  //std::cout << "\n" << phase  << "PI_2 " << "\n" ;
}

