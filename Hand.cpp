#include "Hand.h"

Hand::Hand()
{

}

void Hand::add(Card card)
{
	hand.push_back(card);
}

void Hand::disp()
{
	for (std::vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it)
		cout << "number: " << (*it).number << "\t" << "color: " << (*it).color << "\t" << "special: " << (*it).special << endl;
}

int Hand::getSize()
{
	return hand.size();
}

Card Hand::getCard(int loc_)
{
	return hand.at(loc_);
}

bool Hand::removeCard(int loc_)
{
	hand.erase(hand.begin() + loc_);
	return true;

}