/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Screen.h
 * Author: nickverbeek
 *
 * Created on 20 februari 2018, 13:30
 */

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
    Screen();
    Screen(const Screen& orig);
    virtual ~Screen();
    
    void setScreen(int screenNumber);
    int getScreen();
    
    
    
private:
    void welcomeScreen();
    void askModuleScreen();
    void musicianMenuScreen();
    void musicianTrainerScreen();
    void intervalTrainerScreen();
    
    int screen;
    int excercise;
    int userSelection;
    
};

#endif /* SCREEN_H */

