/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Delay.h"
#include "Biquad.h"

#define INPUT_ID "input"
#define INPUT_NAME "Input"
#define DELAYTIME_ID "delaytime"
#define DELAYTIME_NAME "DelayTime"
#define FEEDBACK_ID "feedback"
#define FEEDBACK_NAME "Feedback"
#define OUTPUT_ID "output"
#define OUTPUT_NAME "Output"
#define LOWPASS_ID "lowpass"
#define LOWPASS_NAME "Lowpass"
#define HIGHPASS_ID "highpass"
#define HIGHPASS_NAME "Highpass"
#define DRYPAN_ID "drypan"
#define DRYPAN_NAME "DryPan"
#define WETPAN_ID "wetpan"
#define WETPAN_NAME "WetPan"
#define DRYMIX_ID "drymix"
#define DRYMIX_NAME "DryMix"
#define WETMIX_ID "wetmix"
#define WETMIX_NAME "WetMix"

//==============================================================================
/**
*/
class DelayAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    DelayAudioProcessor();
    ~DelayAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    Delay *delay;
    
    AudioProcessorValueTreeState treeState;
    
    AudioPlayHead *playHead;
    AudioPlayHead::CurrentPositionInfo positionInfo;
    double bpm;
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayAudioProcessor)
};
