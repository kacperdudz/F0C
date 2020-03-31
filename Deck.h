#ifndef DECK_
#define DECK_

#include <iostream>
using namespace std;

#include "Card.h"
#include <stack>
//using namespace std;

class Deck {
private:
	Card deck[108];
	stack <Card> r_deck;
public:
	Deck();
	/*void Disp();
	void Update(int id_, string name_, int cost_);
	void UpdateBin(int bin_);
	string getName();
	int getBin();
	void dispOrder();
	int getCost();*/
	void quickDisp(int size);
	void shuffle();
	Card getNext();
	//bool operator>(const Equip&) const;
	//bool operator<=(const Equip&) const;
};

#include "Deck.cpp"
#endif DECK_