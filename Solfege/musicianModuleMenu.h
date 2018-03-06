/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   musicianModuleMenu.h
 * Author: nickverbeek
 *
 * Created on 26 februari 2018, 23:04
 */

#ifndef MUSICIANMODULEMENU_H
#define MUSICIANMODULEMENU_H

class musicianModuleMenu {
public:
    musicianModuleMenu();
    musicianModuleMenu(const musicianModuleMenu& orig);
    virtual ~musicianModuleMenu();
    
    void askExercise();
    void checkUserInput(int userInput);
    
    
private:
    int excercise;
    int userSelection;
};

#endif /* MUSICIANMODULEMENU_H */

