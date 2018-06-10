/*
  ==============================================================================

    BiQuad.cpp
    Created: 14 May 2018 5:48:08pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#include "BiQuad.h"

static float x, xx, xxx, y, yy, yyy;

BiQuad::BiQuad(){
    
}

BiQuad::~BiQuad(){
    
}

float BiQuad::process(const float input){
    x = input;
    
    y = ff0 * x + ff1 * xx + ff2 * xxx + fb1 * yy + fb2 * yyy;
    xxx = xx;
    xx = x;
    yyy = yy;
    yy = y;
    return y;
}

void BiQuad::clear(){
    x = 0.0f;
    xx = 0.0f;
    xxx = 0.0f;
    y = 0.0f;
    yy = 0.0f;
    yyy = 0.0f;
}
