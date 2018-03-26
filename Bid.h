/*
 * C++ Game Design Project
 * TA: Greg Hunkins
 *
 * Bid.h by Shuyu Zhou
 *
 */

#ifndef BID_H_
#define BID_H_

class Bid {
private:
	int number;
	int amount;
public:
	Bid(int x = 0, int y = 0);

	//getters
	int getNumber() const;
	int getAmount() const;
	//setters
	void setNumber(int x);
	void setAmount(int y);

};

#endif /* BID_H_ */
