/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DelayAudioProcessorEditor  : public AudioProcessorEditor,
                                    public SliderListener,
                                    public Button::Listener
{
public:
    DelayAudioProcessorEditor (DelayAudioProcessor&);
    ~DelayAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider *slider) override;
    void buttonClicked(Button *button) override;
    
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sliderAttach;

private:
    Slider delayTimeSlider;
    Slider feedbackSlider;
    Slider drySignalLevelSlider;
    Slider wetSignalLevelSlider;
    Slider dryPanSlider;
    Slider wetPanSlider;
    Slider inputLevelSlider;
    Slider outputLevelSlider;
    Slider lowpassSlider;
    Slider highpassSlider;
    
    Label lblDelayTime;
    Label lblFeedback;
    Label lblDrySignalLevel;
    Label lblWetSignalLevel;
    Label lblDryPan;
    Label lblWetPan;
    Label lblInputLevel;
    Label lblOutputLevel;
    Label lblLowpass;
    Label lblHighpass;
    
    ToggleButton btnEnableBPM;
    bool bpmModeEnabled = false;
    
    TextButton btn1Beat;
    TextButton btnHalfBeat;
    TextButton btnQuarterBeat;
    TextButton btnEighthBeat;
    TextButton btnSixteenthBeat;
    
    

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DelayAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayAudioProcessorEditor)
};
