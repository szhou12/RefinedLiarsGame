/*
 * C++ Game Design Project
 *
 * main_Zhou.cpp by Shuyu Zhou
 *
 *
 */



#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

#include <stdlib.h>

#include "Bid.h"
#include "Player.h"

void cls();
int main(){
	/******* Introduction *******/
	cout << "***********Welcome to Liar's Dice game!***********\n";
	cout << "Each player rolls five dice and keeps the result secret from other players.\n";
	cout << "Players then take turns bidding on the total results.\n";
	cout << "The current bid must be higher than the previous bid.\n";
	cout << "If a player believes that the bidding has gone too high, he/she can challenge the previous bid.\n";


	/******* Ask how many players are going to play *******/
	int num;
	int i, j;
	cout <<"\n***********Game Started!***********"<<endl;
	cout<< "How many players are going to play (2 to 6 players): ";
	while(!(cin >> num) || num <= 1 || num > 6){ // input validation
		cout << "Wrong input! Enter an integer (2 to 6): ";
		cin.clear(); // clear the failbit (error flag)
		while(cin.get() != '\n'){} // clear input buffer
	}
	while(cin.get() != '\n'){} // clear input buffer again in case a number is followed by other characters (e.g. 3s)


	/******* Initialize each player *******/
	vector<string> names(num); //dynamic memory allocation
	string player_name;

	// ask for each player's name
	for (i = 0; i < num; i++){
		cout << "Enter name of player #"<<i+1<<": ";
		cin >> player_name;
		while(cin.get() != '\n'){};
		names[i] = player_name;
	}
	cout<<endl;

	// create an class array
	Player players[7] = {
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
			Player("null"),
	};

	// create an array that records each player's score
	int n;
	vector<int> score(num);
	for(n = 0; n < num; n++){
		score[n] = 0;
	}

	int round = 0;

	do{
		srand( (unsigned)time( NULL ) );

		// initialize player's class
		for(i = 0; i < num; i++){
			players[i] = Player(names[i]);
			players[i].rollDice(); // Each player rolls his/her dice
			//players[i].showDice(); // Show each player's own dice
			players[i].countNumber(); // count the amount of each die number in one player's hand
		}



		/*******  Show each player's own dice *******/
		string temp;
		int quit = 0;
		int exist;
		char ch;

		while(quit == 0){
			exist = 0;
			cout << "\nTo check what you've rolled. Enter your name (q to quit if all checked): ";
			cin >> temp;
			// to check whether the name entered is one of names entered at the beginning
			for(i = 0; i < num; i++){
				if (temp.compare(players[i].name) == 0){
					players[i].showDice();
					exist++; // record that the name entered matches with the name stored.

					// hide the previous player's result so that each player can only see his/her own result.
					cout << "Press any key to continue: ";
					ch = getchar();
					while(cin.get() != '\n'){} //clear input buffer
					cls(); // clear screen by printing out a bunch of empty spaces

				}
			}
			if(temp.compare("q") == 0){
				quit = 1;
			} else if(exist == 0 && temp.compare("q") != 0){ // name entered doesn't exist and also no 'q' entered
				cout<<"Wrong name! "<<endl;
				while(cin.get() != '\n'){} //clear input buffer
			}

		}




		/******* Calculate total number of each die number *******/
		int tot_counter[6] = {0};
		for(j = 0; j < 6; j++){
			for(i = 0; i < num; i++){
				tot_counter[j] += players[i].counter[j];
			}
		}

//		for(i = 0; i < 6; i++){
//			cout << tot_counter[i] << " ";
//		}
//		cout<<endl;


		/******* Bidding *******/
		int x, y; // x is the number the player bids on; y is how many number x the player thinks there are in total.
		char callOut;
		int validBid; //index: validBid == 0 means current player bids wrong either on the number or on the amount of the number (either one should be bigger than the bid of previous player)
		int liar = 0; // index: liar == 0 means no one calls out 'liar', so the bidding keeps going on one by one
		int firstOne = 0; //index: fisrtOne == 0 means first bid. firstOne != 0 means later bids.

		Bid p; // create a default bidding class
		cout<<"\n***********Let the bidding begin!***********"<<endl;
		while(liar == 0){
			for(i = 0; i < num; i++){
				cout<<endl;
				cout << players[i].name <<"'s turn: \n";

				if(firstOne != 0){ // input starting from second player
					/* call out or not */
					if (i-1 < 0){
						cout << players[i].name << ", do you think "<<players[num-1].name<<" is a liar? ";
					} else {
						cout << players[i].name << ", do you think "<<players[i-1].name<<" is a liar? ";
					}

					cin >> callOut;
					while (callOut != 'y' && callOut != 'n'){ // input validation
						cout << "Please enter a valid response ('yes' or 'no'): ";
						while(cin.get() != '\n'){} // clear input buffer
						cin >> callOut;
					}
					while(cin.get() != '\n'){} // clear input buffer again

					if(callOut == 'y'){
						// Current player thinks the previous player was lying and calls out. End bidding and reveal the result
						liar = 1;
						break;
					} else if(callOut == 'n'){
						/* no call out. Continue bidding */
						validBid = 0;
						while(validBid == 0){

							cout << players[i].name <<" bids on the number (1-6): ";
							while(!(cin >> x) || x <= 0 || x > 6){ // input validation
								cout << "Wrong input! Enter an integer (1-6): ";
								cin.clear(); // clear the failbit (error flag)
								while(cin.get() != '\n'){} // clear input buffer
							}
							while(cin.get() != '\n'){}

							cout << "How many "<< x <<"(s) are there: ";
							while(!(cin >> y) || y < 0){ // input validation
								cout << "Wrong input! Enter a non-negative number: ";
								cin.clear(); // clear the failbit (error flag)
								while(cin.get() != '\n'){} // clear input buffer
							}
							while(cin.get() != '\n'){}

							// check whether this person is bidding higher
							if(x <= p.getNumber() && y <= p.getAmount()){
								//current player violates the rule. Asking his/her to bid again
								cout << "Please bid higher than the previous player. Bid again!"<<endl;
							}else{
								// current player gives correct bid. End his/her bidding turn.
								validBid = 1;
								p.setNumber(x);
								p.setAmount(y);
							}
						}
					}

				} else { // first bid
					cout << players[i].name <<" bids on the number (1-6): ";
					while(!(cin >> x) || x <= 0 || x > 6){ // input validation
						cout << "Wrong input! Enter an integer (1-6): ";
						cin.clear(); // clear the failbit (error flag)
						while(cin.get() != '\n'){} // clear input buffer
					}
					while(cin.get() != '\n'){}

					cout << "How many "<< x <<"(s) are there: ";
					while(!(cin >> y) || y < 0){ // input validation
						cout << "Wrong input! Enter a non-negative integer: ";
						cin.clear(); // clear the failbit (error flag)
						while(cin.get() != '\n'){} // clear input buffer
					}
					while(cin.get() != '\n'){}

					p.setNumber(x);
					p.setAmount(y);
					firstOne = 1;
				}

			}
		}

		/******* Reveal and check *******/
		cout<<endl;



		if(tot_counter[p.getNumber() - 1] >= p.getAmount()){
			// If total amount of number x is >= the previous player's bid, then current player guessed wrong. The current player'll lose one point.
			cout << players[i].name << " guessed wrong!"<<endl;
			score[i]--;
			if (i-1 < 0){
				score[num-1]++;
			} else {
				score[i-1]++;
			}

		} else {
			// If total amount of number x is < the previous player's bid, then current player'll win one point.
			cout << players[i].name << " guessed right!" << endl;
			score[i]++;
			if (i-1 < 0){
				score[num-1]--;
			} else {
				score[i-1]--;
			}

		}


		/******* Continue the game or not *******/
		cout<<"\nOne more round? ";
		char ans;
		cin >> ans;
		while (ans != 'y' && ans != 'n'){ // input validation
			cout << "Please enter a valid response ('yes' or 'no'): ";
			while(cin.get() != '\n'){} // clear input buffer
			cin >> ans;
		}
		while(cin.get() != '\n'){} // clear input buffer again
		if(ans == 'n'){
			round = 1; // End the game.
		}

	}while(round == 0);
	// round == 0 means players will have one more round.
	// Restart the game without changing each player's name and order.


	/******* Report final scores *******/
	cout << "\n***********Game Over!***********" <<endl;
	cout << "Final scores:" <<endl;
	for(i = 0; i < num; i++){
		cout << players[i].name <<": "<<score[i]<<"\n";
	}


	return 0;
}


void cls() {
	int i;
    for (i = 0; i < 250; ++i) {
        cout << endl;
    }
}
