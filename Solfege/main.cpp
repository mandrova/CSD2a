#include <iostream>
#include <thread>
#include <unistd.h>

#include "jack_module.h"
#include "sine.h"
#include "mtofConverter.h"
#include "Screen.h"
#include "AudioPlayer.h"
#include "IntervalGenerator.h"


int main(int argc,char **argv)
{
    //create an instance of screen
    Screen screen;
    
    //set welcomescreen
    screen.setScreen(0);
    screen.setScreen(1);//set askModuleScreen
    
    //create an instance of IntervalTrainer
    screen.setScreen(4);
    
    //create an instance of IntervalGenerator
    IntervalGenerator intGen;
    
    intGen.generateInterval(); //Create a interval

    
    int firstNote = intGen.getFirstIntervalNote();//get the first note from the created interval
    int secondNote = intGen.getSecondIntervalNote();//get the second note from the created interval    

    AudioPlayer audio;
    audio.playAudio(firstNote, secondNote);
    usleep(1000);

    
    
  //end the program
  return 0;
} // main()
