/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   musicianModule.cpp
 * Author: nickverbeek
 * 
 * Created on 26 februari 2018, 23:02
 */

#include "musicianModule.h"
#include "musicianModuleMenu.h"

musicianModule::musicianModule() {
}

musicianModule::musicianModule(const musicianModule& orig) {
}

musicianModule::~musicianModule() {
}

void musicianModule::musicianTrainer(){
    musicianModuleMenu menu;
    menu.askExercise();
}

