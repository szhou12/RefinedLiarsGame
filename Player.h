/*
 * C++ Game Design Project
 *
 * Player.h by Shuyu Zhou
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int DICE = 5; // number of dice each player has

class Player {
private:
	int hand[DICE];

public:
	//constructor prototype
	Player(string n);

	string name;
	int counter[6];

	void rollDice();
	void showDice();
	void countNumber();

};

#endif /* PLAYER_H_ */
