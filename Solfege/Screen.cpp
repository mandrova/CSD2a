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
#include "musicianModule.h"
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
    
    musicianModule musMod;
    musMod.musicianTrainer();
}

void Screen::musicianTrainerScreen(){
    system("clear");//clear all text in terminal
    //top screen text
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "--------------Musician Interval Trainer--------------" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    
    
    //std::thread firstNoteThread {&IntervalTrainer::playNote, firstNote, IntervalTrainer()};
    //firstNoteThread.
    //usleep(1000);
    //midi.stopRunning();
    //std::thread secondNoteThread {&IntervalTrainer::playNote, IntervalTrainer()};
    //usleep(1000);
    //midi.stopRunning();
}

void play(){
    
}