/*
  ==============================================================================

    BiQuad.h
    Created: 14 May 2018 5:48:08pm
    Author:  Nick Verbeek

  ==============================================================================
*/

#pragma once

class BiQuad{
public:
    BiQuad();
    ~BiQuad();
    
    float process(float x);
    void clear();
    
private:
    
    float ff0 = 0.02107243f;
    float ff1 = 0.04214485f;
    float ff2 = 0.02107243f;
    float fb1 = 0.4f;
    float fb2 = 0.48827803f;
};
