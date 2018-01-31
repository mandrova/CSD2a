/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nickverbeek
 *
 * Created on 31 januari 2018, 15:56
 */

#include <cstdlib>
#include "Trumpet.h"
#include "Brass.h"
#include "Instrument.h"
#include "Strings.h"
#include "Violin.h"

using namespace std;

/*
 * 
 */
int main(int argc, char **argv){
        
	Trumpet trompet("Bes Trumpet", "brass", "Bleeeeeh");
        //trompet.~Trumpet();
	trompet.playMultipleSounds(10);
        
        Violin viool(5, "Strings", "Hoooooooow");
        viool.playMultipleSounds(10);

	return 0;
}

