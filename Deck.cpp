#include "Deck.h"

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
using namespace std;

Deck::Deck()
{
	Card temp;
	int d = 0;
	//filling array with colored + num cards 1-9
	for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < 4; j++, d++)
			{
				switch (j)
				{
				case red: deck[d].color = red; break;
				case yellow: deck[d].color = yellow; break;
				case green: deck[d].color = green; break;
				case blue: deck[d].color = blue; break;
				}
				deck[d].number = i;
				deck[d].special = none_s;
			}
		}
	}
		
	//filling array with 0s
	for (int i = 0; i < 4; i++,d++)
		{
			switch (i)
			{
			case red: deck[d].color = red; break;
			case yellow: deck[d].color = yellow; break;
			case green: deck[d].color = green; break;
			case blue: deck[d].color = blue; break;
			}
			deck[d].number = 0;
			deck[d].special = none_s;
		}

	//filling array with colored special cards
	for (int k = 0; k < 2; k++)
	{
		for (int s = 0; s < 3; s++)
		{
			for (int c = 0; c < 4; c++, d++)
			{
				switch (c)
				{
				case red: deck[d].color = red; break;
				case yellow: deck[d].color = yellow; break;
				case green: deck[d].color = green; break;
				case blue: deck[d].color = blue; break;
				}
				deck[d].number = -1;
				switch (s)
				{
				case skip: deck[d].special = skip; break;
				case Special::reverse: deck[d].special = Special::reverse; break;
				case plus_2: deck[d].special = plus_2; break;
				}
			}
		}
	}

	//filling array with non-colored special cards
	for (int k = 3; k < 5; k++)
	{
		for (int s = 0; s < 4; s++, d++)
		{
			switch (k)
			{
			case plus_4: deck[d].special = plus_4; break;
			case color_change: deck[d].special = color_change; break;
			}
			deck[d].color = none_c;
			deck[d].number = -1;
		}
	}
	srand(time(0));
}

void Deck::quickDisp(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "number: " << deck[i].number << "\t" << "color: " << deck[i].color << "\t" << "special: " << deck[i].special << endl;
	}
}

void Deck::shuffle()
{
	int second;
	Card temp;

	for (int first = 0; first < 108; first++)
	{
		//basically swapping
		//Card temp is used to make sure one of each card is present
		second = (rand() % 108);
		temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;
	}

	for (int i = 0; i < 108; i++)
	{
		//basically swapping
		//Card temp is used to make sure one of each card is present
		r_deck.push(deck[i]);
	}

}

Card Deck::getNext()
{
	Card top = r_deck.top();
	r_deck.pop();
	return top;
}