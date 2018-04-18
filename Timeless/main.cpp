/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nickverbeek
 *
 * Created on 16 april 2018, 14:13
 */


#include <cstdlib>
#include <iostream>
#include <thread>
#include "jack_module.h"
#include "Delay.h"

JackModule jack;
Delay delayEffect;


static void effect(){
    //hier komt de verwijzing naar het effect.
    delayEffect.process(jack);
}

/*
 * 
 */
int main(int argc, char** argv) {
    std::cout << "Starting Program" << std::endl;
    jack.init();
    std::cout << "Jack Initiated" << std::endl;
    jack.autoConnect();
    std::cout << "Jack Connected" << std::endl;
    
    std::thread filterThread(effect);
    
    filterThread.join();
    
    
    return 0;
}

