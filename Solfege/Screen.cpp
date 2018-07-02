/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Screen.cpp
 * Author: nickverbeek
 * 
 * Created on 20 februari 2018, 13:30
 */

#include <iostream>
#include <valarray>
#include <thread>
#include <time.h>
#include <unistd.h>

#include "Screen.h"
#include "IntervalTrainer.h"
#include "IntervalGenerator.h"
#include "Interval.h"
#include "AudioPlayer.h"

Screen::Screen() {
}

Screen::Screen(const Screen& orig) {
}

Screen::~Screen() {
}

//Set screen and show the selected screen
void Screen::setScreen(int screenNumber){
    this->screen = screenNumber;
    switch(this->screen){
        case 0 : welcomeScreen();
            break;
        case 1 : askModuleScreen();
            break;
        case 2 : musicianMenuScreen();
            break;
        case 3 : musicianTrainerScreen();
            break;
        case 4: intervalTrainerScreen();
            break;
    }
}

int Screen::getScreen(){
    return this->screen;
}

void Screen::welcomeScreen(){
    system("clear");
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "--------------Welcome to Solfege 3000----------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
}

//Let the user decide which trainer he wants to use
void Screen::askModuleScreen(){
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "Choose 0 for Musician Trainer and 1 for Audio trainer" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    int userSelection;
    
    while(true){
        std::cout << "> ";
        //ask userInput for desired trainer
        std::cin >> userSelection;
        //check if selection isn't int
        
        
        //check of input is an integer
        while (!std::cin.good()){
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "No correct number has been given. Please try again" << std::endl;
            std::cout << "Please use numbers 0 and 1 for the selection------" << std::endl;
            std::cout << "> ";
            std::cin >> userSelection;
        }
        
        //select the right screen as the user has given.
        switch(userSelection){
            case 0 : std::cout << "Musician Trainer has been selected" << std::endl;
                    setScreen(2);//show musicionScreen
                break;
            case 1 : std::cout << "Audio Trainer has been selected" << std::endl;
                break;
        }
            break;
    }
}
    


void Screen::musicianMenuScreen(){
    system("clear");//clear all text in terminal
    //top screen text
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "--------------------Musician Menu--------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    //instruction text
    std::cout << "------Please select the desired trainer. Choose: ----" << std::endl;
    std::cout << "-----------------0: Interval Trainer-----------------" << std::endl;
    std::cout << "-----------------1: Scale Trainer--------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    //ask user input
    std::cout << "> ";
    std::cin >> this->userSelection;
    
    //check if input is an integer. Otherwise try again.
    while(!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "No correct number has been given. Please try again" << std::endl;
        std::cout << "Please use numbers 0 and 1 for the selection------" << std::endl;
        std::cout << "> ";
        std::cin >> this->userSelection;
    }
    
    switch(this->userSelection){
        case 0: setScreen(3);
            break;
        //case 1: //link to scale trainer. Future function
            //break;
    }
}

void Screen::musicianTrainerScreen(){
    system("clear");//clear all text in terminal
    //top screen text
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "--------------Musician Interval Trainer--------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
}

void Screen::intervalTrainerScreen(){
    //top text
    std::cout << "-----------------------Rules-------------------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "A Interval will be generated. Every interval has two " << std::endl;
    std::cout << "notes. Wich will be played in serial. The interval \n"
            "can be replayed by typing 'play' and hit enter. By using\n"
            "the intervallist you can choose the right interval that \n"
            "has been played." << std::endl;
}

