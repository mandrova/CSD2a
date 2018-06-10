/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayAudioProcessor::DelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
    treeState(*this, nullptr)
#endif
{
    NormalisableRange<float> inputRange(0, 100);
    NormalisableRange<float> outputRange(0, 100);
    NormalisableRange<float> delaytimeRange(20, 1000);
    NormalisableRange<float> feedbackRange(0, 100);
    NormalisableRange<float> lowpassRange(1000, 20000);
    NormalisableRange<float> highpassRange(0, 4000);
    NormalisableRange<float> dryPanRange(-100, 100);
    NormalisableRange<float> wetPanRange(-100, 100);
    NormalisableRange<float> dryMixRange(0, 100);
    NormalisableRange<float> wetMixRange(0, 100);
    
    treeState.createAndAddParameter(INPUT_ID, INPUT_NAME, INPUT_NAME, inputRange, 80, nullptr, nullptr);
    treeState.createAndAddParameter(OUTPUT_ID, OUTPUT_NAME, OUTPUT_NAME, outputRange, 80, nullptr, nullptr);
    treeState.createAndAddParameter(DELAYTIME_ID, DELAYTIME_NAME, DELAYTIME_NAME, delaytimeRange, 500, nullptr, nullptr);
    treeState.createAndAddParameter(FEEDBACK_ID, FEEDBACK_NAME, FEEDBACK_NAME, feedbackRange, 50, nullptr, nullptr);
    treeState.createAndAddParameter(LOWPASS_ID, LOWPASS_NAME, LOWPASS_NAME, lowpassRange, 20000, nullptr, nullptr);
    treeState.createAndAddParameter(HIGHPASS_ID, HIGHPASS_NAME, HIGHPASS_NAME, highpassRange, 0, nullptr, nullptr);
    treeState.createAndAddParameter(DRYPAN_ID, DRYPAN_NAME, DRYPAN_NAME, dryPanRange, 0, nullptr, nullptr);
    treeState.createAndAddParameter(WETPAN_ID, WETPAN_NAME, WETPAN_NAME, wetPanRange, 0, nullptr, nullptr);
    treeState.createAndAddParameter(DRYMIX_ID, DRYMIX_NAME, DRYMIX_NAME, dryMixRange, 80, nullptr, nullptr);
    treeState.createAndAddParameter(WETMIX_ID, WETMIX_NAME, WETMIX_NAME, wetMixRange, 50, nullptr, nullptr);
}

DelayAudioProcessor::~DelayAudioProcessor()
{
}

//==============================================================================
const String DelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DelayAudioProcessor::setCurrentProgram (int index)
{
}

const String DelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void DelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    delay = new Delay();
    delay->setSampleRate(getSampleRate());
    delay->init(getTotalNumInputChannels());
    
    bpm = 120;
}

void DelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    //delay->init(getTotalNumInputChannels());
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DelayAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    //Clearing buffer
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    //Processing audio
    for (int sample=0; sample < buffer.getNumSamples(); ++sample){
        for (int channel = 0; channel < totalNumInputChannels; ++channel){
            auto* channelData = buffer.getWritePointer (channel);
            
            float input[2];
            input[channel] = buffer.getSample(channel, sample);
            
            //processing samples through delay. then multiplay with the ouput level.
            channelData[sample] = delay->getOutputLevel() * delay->process(channel, input[channel]);
            
        }//for(channel)
    }//for(sample)
}

//==============================================================================
bool DelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DelayAudioProcessor::createEditor()
{
    return new DelayAudioProcessorEditor (*this);
}

//==============================================================================
void DelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayAudioProcessor();
}
