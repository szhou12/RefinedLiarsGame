/*
 * C++ Game Design Project
 * TA: Greg Hunkins
 *
 * Player.cpp by Shuyu Zhou
 *
 */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#include "Player.h"

//constructor definition: automatically initialize Player object when created
Player::Player(string n){
	name = n;
}

// Roll dice. Randomly generate 5 numbers whose value is ranging from 1 to 6.
void Player::rollDice(){
	int i;
	for(i = 0; i< DICE; i++){
		hand[i] = rand()%6+1;
	}
}

// Show each player what s/he has at hand.
void Player::showDice(){
	int i;
	cout << name<<": ";
	for(i = 0; i< DICE; i++){
		cout << hand[i] << " ";
	}
	puts("\n");
}

// Count the amount of each number (1-6) the player has at hand. Used to calculate total amount of each number in the game.
void Player::countNumber(){
	int i, j;
	for(i = 0; i<6; i++){
		counter[i] = 0;
	}
	for(j = 0; j < DICE; j++){
		counter[hand[j] - 1]++;
	}
}

