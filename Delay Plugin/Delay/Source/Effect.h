//
//  Effect.h
//  Delay
//
//  Created by Nick Verbeek on 04-05-18.
//

#ifndef Effect_h
#define Effect_h

class Effect
{
public:
    Effect();
    ~Effect();
    
    void setInputLevel(float);
    void setOutputLevel(float);
    
    float getInputLevel();
    float getOutputLevel();
    
private:
    float inputLevel;
    float outputLevel;
};

#endif /* Effect_h */
