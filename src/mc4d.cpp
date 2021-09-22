
#include <iostream>
#include "mc4d.h"

MC4D::MC4D() {
    generateDraw();
}

void MC4D::generateDraw() {
    for(int i=0; i<23; ++i) {
        draw.push_back((std::rand() % 10000));
    }
}

double MC4D::match(int guess, int bet) {
	int prize = 0;
	if(guess == draw[0]) prize += 2000*bet;
	if(guess == draw[1]) prize += 1000*bet;
	if(guess == draw[2]) prize += 490*bet;
	for(int i=3; i<13; ++i) {
		if(guess == draw[i]) {
			prize += 250*bet;
		}
	}
	for(int i=13; i<23; ++i) {
		if(guess == draw[i]) {
			prize += 60*bet;
		}
	}
	
	return prize-bet;
}

double MC4D::run(int guess, int bet) {
	int numDays = 10*3*52;
	int outcome = 0;
	for(int i=0; i<numDays; ++i) {
		outcome += match(guess, bet);
	}
	
	return outcome;
}

void MC4D::display() {
    for(int i=0; i<draw.size(); ++i) {
        std::cout << draw[i] << "\t";
    }

    std::cout << std::endl;
}