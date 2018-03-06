#include <iostream>
#include <thread>
#include <unistd.h>
#include "jack_module.h"
#include "sine.h"
#include "mtofConverter.h"
#include "Screen.h"
#include "musicianModule.h"
#include "AudioPlayer.h"
#include "IntervalGenerator.h"
#include "IntervalTrainer.h"


int main(int argc,char **argv)
{
    Screen screen;
    
    //set welcomescreen
    screen.setScreen(0);
    
    musicianModule musMod;
    screen.setScreen(1);//set askModuleScreen
    //musMod.musicianTrainer();
    
    //create an instance of IntervalTrainer
    IntervalTrainer intTrainer;
    intTrainer.showRules();//show rules of this trainer
    
    //create an instance of IntervalGenerator
    IntervalGenerator intGen;
    
    while (true){
        intGen.generateInterval(); //Create a interval

        std::cout << "A new interval has been generated." << std::endl;

        int firstNote = intGen.getFirstIntervalNote();//get the first note from the created interval
        int secondNote = intGen.getSecondIntervalNote();//get the second note from the created interval

        
        AudioPlayer audio;
        audio.playAudio(firstNote, secondNote);
        usleep(1000);
        audio.~AudioPlayer();

        std::cout << "Give the right answer below" << std::endl;
        std::cout << "> ";
        int userSelection;

        while (true){
            std::cin >> userSelection;
            if (!std::cin.fail()){
                
                if (userSelection == intGen.getAnswer()){
                    std::cout << "Congradulations. The right answer has been given" << std::endl;
                    std::cout << "Lets make a new interval" << std::endl;
                    break;
                }
                else {
                    std::cout << "Wrong answer. Please try again" << std::endl;
                    std::cout << "> ";
                }
                
                
            }
            else {
                std::cout << "Please try number. Try again" << std::endl;
            }
            
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }
    
    
    
    
    //Midi converter
    //mtofConverter noteConverter;
    //noteConverter.mtof(60);
    
    //int input;
    //std::cin >> input;
    //std::cout << "Note: " << input << " is geconvert naar: " << noteConverter.mtof(input) << std::endl;

  //end the program
  return 0;
} // main()
