/*
 * C++ Game Design Project
 * TA: Greg Hunkins
 *
 * Bid.cpp by Shuyu Zhou
 *
 */

#include "Bid.h"
#include <iostream>


Bid::Bid(int x, int y) {
	number = x;
	amount = y;

}

int Bid::getNumber() const{
	return number;
}
int Bid::getAmount() const{
	return amount;
}

void Bid::setNumber(int x){
	number = x;
}

void Bid::setAmount(int y){
	amount = y;
}
