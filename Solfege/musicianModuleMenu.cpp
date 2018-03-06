/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   musicianModuleMenu.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:04
 */

#include <iostream>
#include <istream>

#include "musicianModuleMenu.h"
#include "Screen.h"

musicianModuleMenu::musicianModuleMenu() {
}

musicianModuleMenu::musicianModuleMenu(const musicianModuleMenu& orig) {
}

musicianModuleMenu::~musicianModuleMenu() {
}

void musicianModuleMenu::askExercise(){
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
    
    checkUserInput(this->userSelection);
}

void musicianModuleMenu::checkUserInput(int userInput){
    Screen screen;
    switch(userInput){
        case 0: screen.setScreen(3);
            break;
        //case 1: //link to scale trainer. Future function
            //break;
    }
}