#ifndef HAND_
#define HAND_

#include <vector>
using namespace std;

#include "Card.h"

class Hand {
private:
	vector<Card> hand;
public:
	Hand();
	void add(Card card);
	void disp();
	int getSize();
	Card getCard(int loc_);
	bool removeCard(int loc_);
	/*void Update(int id_, string name_, int cost_);
	void UpdateBin(int bin_);
	string getName();
	int getBin();
	void dispOrder();
	int getCost();*/

	//bool operator>(const Equip&) const;
	//bool operator<=(const Equip&) const;
};

#include "Hand.cpp"
#endif HAND_
