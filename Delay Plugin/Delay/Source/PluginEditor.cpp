/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayAudioProcessorEditor::DelayAudioProcessorEditor (DelayAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (550, 410);
    //DelayTimeSlider Settings
    delayTimeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    delayTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> delayTimeRange;
    delayTimeRange.setStart(20);
    delayTimeRange.setEnd(1000);
    
    delayTimeSlider.setRange(delayTimeRange, 1);
    delayTimeSlider.setValue(500);
    delayTimeSlider.addListener(this);
    addAndMakeVisible(delayTimeSlider);
    
    //setting label for the DelayTimeSlider
    lblDelayTime.setText("Delay Time", dontSendNotification);
    //end delayTimeSlider settings
    //===================================================================================================
    
    //FeedbackSlider Settings
    feedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    feedbackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> feedbackRange;
    feedbackRange.setStart(0);
    feedbackRange.setEnd(100);
    
    feedbackSlider.setRange(feedbackRange, 1);
    feedbackSlider.setValue(50);
    feedbackSlider.addListener(this);
    addAndMakeVisible(feedbackSlider);
    
    //settings for the label of FeedbackSlider
    lblFeedback.setText("Feedback", dontSendNotification);
    //end feedbackSlider settings
    //===================================================================================================
    
    //DrySignalLevelSlider Settings
    drySignalLevelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    drySignalLevelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> drySignalLevelRange;
    drySignalLevelRange.setStart(0);
    drySignalLevelRange.setEnd(100);
    
    drySignalLevelSlider.setRange(drySignalLevelRange, 0.1);
    drySignalLevelSlider.setValue(80);
    drySignalLevelSlider.addListener(this);
    addAndMakeVisible(drySignalLevelSlider);
    
    //settings for the label of drySignalLevelSlider
    lblDrySignalLevel.setText("Dry Level", dontSendNotification);
    //End of drySignalLevelSlider settings
    //===================================================================================================
    
    //WetSignalLevelSlider Settings
    wetSignalLevelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    wetSignalLevelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> wetSignalLevelRange;
    wetSignalLevelRange.setStart(0);
    wetSignalLevelRange.setEnd(100);
    
    wetSignalLevelSlider.setRange(wetSignalLevelRange, 0.1);
    wetSignalLevelSlider.setValue(50);
    wetSignalLevelSlider.addListener(this);
    addAndMakeVisible(wetSignalLevelSlider);
    
    //settings for the label of wetSignalLevelSlider
    lblWetSignalLevel.setText("Wet Level", dontSendNotification);
    //end of wetSignalLevelSlider settings
    //===================================================================================================
    
    //DryPanSlider Settings
    dryPanSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    dryPanSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> dryPanRange;
    dryPanRange.setStart(-100);
    dryPanRange.setEnd(100);
    
    dryPanSlider.setRange(dryPanRange, 1);
    dryPanSlider.setValue(0);
    dryPanSlider.addListener(this);
    addAndMakeVisible(dryPanSlider);
    
    //settings of the label of dryPanSlider
    lblDryPan.setText("Dry Pan", dontSendNotification);
    //end of dryPanSlider settings
    //===================================================================================================
    
    //WetPanSlider Settings
    wetPanSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    wetPanSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> wetPanRange;
    wetPanRange.setStart(-100);
    wetPanRange.setEnd(100);
    
    wetPanSlider.setRange(wetPanRange, 1);
    wetPanSlider.setValue(0);
    wetPanSlider.addListener(this);
    addAndMakeVisible(wetPanSlider);
    
    //settings of the label of wetPanSlider
    lblWetPan.setText("Wet Pan", dontSendNotification);
    //end of wetPanSlider settings
    //===================================================================================================
    
    //InputLevelSlider Settings
    inputLevelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    inputLevelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> inputLevelRange;
    inputLevelRange.setStart(0);
    inputLevelRange.setEnd(100);
    
    inputLevelSlider.setRange(inputLevelRange, 0.1);
    inputLevelSlider.setValue(80);
    inputLevelSlider.addListener(this);
    addAndMakeVisible(inputLevelSlider);
    
    //settings of the label of inputLevelSlider
    lblInputLevel.setText("Input", dontSendNotification);
    
    //end of inputLevelSlider settings
    //===================================================================================================
    
    //OutputLevelSlider Settings
    outputLevelSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    outputLevelSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> outputLevelRange;
    outputLevelRange.setStart(0);
    outputLevelRange.setEnd(100);
    
    outputLevelSlider.setRange(outputLevelRange, 0.1);
    outputLevelSlider.setValue(80);
    outputLevelSlider.addListener(this);
    addAndMakeVisible(outputLevelSlider);
    
    //settings of the label of outputLevelSlider
    lblOutputLevel.setText("Output", dontSendNotification);
    //end of outputLevelSlider settings
    //===================================================================================================
    
    //LowpassSlider settings
    lowpassSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lowpassSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> lowpassRange;
    lowpassRange.setStart(1000);
    lowpassRange.setEnd(20000);
    
    lowpassSlider.setRange(lowpassRange, 1);
    lowpassSlider.setValue(20000);
    lowpassSlider.addListener(this);
    addAndMakeVisible(lowpassSlider);
    
    //settings of the label of lowpassSlider
    lblLowpass.setText("Lowpass", dontSendNotification);
    //end of lowpassSlider settings
    //===================================================================================================
    
    //HighpassSlider settings
    highpassSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    highpassSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 20);
    
    Range<double> highpassRange;
    highpassRange.setStart(0);
    highpassRange.setEnd(4000);
    
    highpassSlider.setRange(highpassRange, 1);
    highpassSlider.setValue(0);
    highpassSlider.addListener(this);
    addAndMakeVisible(highpassSlider);
    
    //settings of the label of highpassSlider
    lblHighpass.setText("Highpass", dontSendNotification);
    //end of highpassSlider settings
    //===================================================================================================
    
    //settings of BPM button not visible for now.
    //Still issues with changing the delaybuffer.
    btnEnableBPM.setButtonText("BPM");
    btnEnableBPM.addListener(this);
    addAndMakeVisible(btnEnableBPM);
    btnEnableBPM.setVisible(false);
    
    //Bpm based button configuration
    btn1Beat.setButtonText("1/1");
    btn1Beat.addListener(this);
    addAndMakeVisible(btn1Beat);
    btn1Beat.setVisible(false);
    
    btnHalfBeat.setButtonText("1/2");
    btnHalfBeat.addListener(this);
    addAndMakeVisible(btnHalfBeat);
    btnHalfBeat.setVisible(false);
    
    btnQuarterBeat.setButtonText("1/4");
    btnQuarterBeat.addListener(this);
    addAndMakeVisible(btnQuarterBeat);
    btnQuarterBeat.setVisible(false);
    
    btnEighthBeat.setButtonText("1/8");
    btnEighthBeat.addListener(this);
    addAndMakeVisible(btnEighthBeat);
    btnEighthBeat.setVisible(false);
    
    btnSixteenthBeat.setButtonText("1/16");
    btnSixteenthBeat.addListener(this);
    addAndMakeVisible(btnSixteenthBeat);
    btnSixteenthBeat.setVisible(false);
}

DelayAudioProcessorEditor::~DelayAudioProcessorEditor()
{
}

//==============================================================================
void DelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    g.setColour(Colours::white);
    g.setFont(15.0f);
    
    
    //showing upper textfields
    g.drawFittedText("Input", 10, 10, 100, 15, Justification::centred, 1);
    if(bpmModeEnabled){
        g.drawFittedText("Delay Time", 140, 10, 100, 15, Justification::centred, 1);
    } else {
        g.drawFittedText("Note Length", 140, 10, 100, 15, Justification::centred, 1);
    }
    g.drawFittedText("Feedback", 300, 10, 100, 15, Justification::centred, 1);
    g.drawFittedText("Output", 430, 10, 100, 15, Justification::centred, 1);
    
    //draw interface lines
    g.setColour(Colours::grey);
    g.setOpacity(0.5);
    g.drawLine(10, 195, 540, 195, 1);
    g.drawLine(130, 10, 130, 195, 1);
    g.drawLine(410, 10, 410, 195, 1);
    g.drawLine(240, 195, 240, 400, 1);
    g.drawLine(410, 195, 410, 400, 1);
    g.setColour(Colours::white);
    g.setOpacity(1);
    
    //showing lower text labels
    g.drawFittedText("Lowpass", 10, 230, 100, 15, Justification::centred, 1);
    g.drawFittedText("Highpass", 130, 230, 100, 15, Justification::centred, 1);
    g.drawFittedText("Dry Pan", 320, 230, 100, 15, Justification::centred, 1);
    g.drawFittedText("Wet Pan", 320, 330, 100, 15, Justification::centred, 1);
    g.setFont(17.0f);
    g.drawFittedText("Mix", 430, 200, 110, 15, Justification::centred, 1);
    g.setFont(15.0f);
    g.drawFittedText("Dry", 430, 230, 50, 15, Justification::centred, 1);
    g.drawFittedText("Wet", 490, 230, 50, 15, Justification::centred, 1);
    
    
}

void DelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //Setting bound to all elements
    inputLevelSlider.setBounds(10, 30, 100, 150);
    lblInputLevel.setBounds(10, 10, 100, 15);
    delayTimeSlider.setBounds(140, 30, 100, 150);
    feedbackSlider.setBounds(300, 30, 100, 150);
    outputLevelSlider.setBounds(430, 30, 100, 150);
    
    lowpassSlider.setBounds(10, 250, 100, 150);
    highpassSlider.setBounds(130, 250, 100, 150);
    dryPanSlider.setBounds(250, 200, 100, 100);
    wetPanSlider.setBounds(250, 300, 100, 100);
    drySignalLevelSlider.setBounds(425, 250, 50, 150);
    wetSignalLevelSlider.setBounds(485, 250, 50, 150);
    
    btnEnableBPM.setBounds(230, 10, 60, 20);
    
    btn1Beat.setBounds(140, 40, 100, 20);
    btnHalfBeat.setBounds(140, 70, 100, 20);
    btnQuarterBeat.setBounds(140, 100, 100, 20);
    btnEighthBeat.setBounds(140, 130, 100, 20);
    btnSixteenthBeat.setBounds(140, 160, 100, 20);
}

void DelayAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if (slider == &delayTimeSlider){
        processor.delay->setDelayTime(delayTimeSlider.getValue());
    } else if(slider == &inputLevelSlider){
        processor.delay->setInputLevel(inputLevelSlider.getValue()/100);
    } else if(slider == &outputLevelSlider){
        processor.delay->setOutputLevel(outputLevelSlider.getValue()/100);
    } else if(slider == &feedbackSlider){
        processor.delay->setFeedback(feedbackSlider.getValue()/100);
    } else if(slider == &lowpassSlider){
        processor.delay->setLowpassFilter(lowpassSlider.getValue());
    } else if(slider == &highpassSlider){
        processor.delay->setHighpassFilter(highpassSlider.getValue());
    } else if(slider == &drySignalLevelSlider){
        processor.delay->setDryLevel(drySignalLevelSlider.getValue()/100);
    } else if(slider == &wetSignalLevelSlider){
        processor.delay->setWetLevel(wetSignalLevelSlider.getValue()/100);
    } else if(slider == &dryPanSlider){
        processor.delay->setDrySignalPanning(dryPanSlider.getValue());
    } else if(slider == &wetPanSlider){
        processor.delay->setWetSignalPanning(wetPanSlider.getValue());
    }
}

void DelayAudioProcessorEditor::buttonClicked(Button *button){
    //when bpmMode is enabled do this
    if(button == &btnEnableBPM){
        bool visible;
        if(bpmModeEnabled){
            delayTimeSlider.setVisible(true);
            visible = false;
            btn1Beat.setVisible(visible);
            btnHalfBeat.setVisible(visible);
            btnQuarterBeat.setVisible(visible);
            btnEighthBeat.setVisible(visible);
            btnSixteenthBeat.setVisible(visible);
            bpmModeEnabled = false;
        } else {
            delayTimeSlider.setVisible(false);
            visible = true;
            btn1Beat.setVisible(visible);
            btnHalfBeat.setVisible(visible);
            btnQuarterBeat.setVisible(visible);
            btnEighthBeat.setVisible(visible);
            btnSixteenthBeat.setVisible(visible);
            bpmModeEnabled = true;
        }
    } else {
        //change state so that the selected value is shown
        button->setState(Button::buttonDown);
        
        //filter used button to calculate delaytimes depending on bpm
        if(button == &btn1Beat){
            processor.delay->setDelayTime(((60 / processor.bpm) * 1000) * 4);
        } else if(button == &btnHalfBeat){
            processor.delay->setDelayTime(((60 / processor.bpm) * 1000) * 2);
        } else if(button == &btnQuarterBeat){
            processor.delay->setDelayTime((60 / processor.bpm) * 1000);
        } else if(button == &btnEighthBeat){
            processor.delay->setDelayTime(((60 / processor.bpm) / 2) * 1000);
        } else if(button == &btnSixteenthBeat){
            processor.delay->setDelayTime(((60 / processor.bpm) / 4) * 1000);
        }
    }
}
