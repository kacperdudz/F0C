#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <stack>

using namespace std;

Deck * newDeck();

bool checkRange(Hand, int);

bool checkMove(Hand, int, Card);

int main()
{

	Deck game_deck = *newDeck();
	Hand h1, h2, cur_hand;
	bool game_state = true, draw;
	int loc;
	int counter = 0;
	//deck.quickDisp(108);
	
	game_deck.shuffle();
	//game_deck.quickDisp(108);
	
	cout << endl;

	stack<Card> pile;
	pile.push(game_deck.getNext());

	for (int i = 0; i < 7; i++)
	{
		h1.add(game_deck.getNext());
		h2.add(game_deck.getNext());
	}

	h1.disp();
	cout << endl;
	//h2.disp();
	//cout << endl;

	cout << "number: " << pile.top().number << "\t" << "color: " << pile.top().color << "\t" << "special: " << pile.top().special << endl;

	cur_hand = h1;
	while (game_state)
	{
		if (counter > 0) {
			cout << "place rebuttal? (enter -1 for \"no\")\n";
			cin >> draw;
			while (draw) {
				cout << "reubttal pos\n";
				cin >> loc;
				loc--;
				while (loc < 0 && loc > cur_hand.getSize()) {
					cout << "index not in hand, try again:\n";
					cout << "reubttal pos\n";
					cin >> loc;
					loc--;
				}
				cout << "place rebuttal?(enter -1 for \"no\")\n";
				cin >> draw;
			}
			cout << "did not place rebuttal\n";
			//code to draw counter amount; then empty counter
		}
		else {
			cout << "draw?\n";
			cin >> draw;
			if (draw)
			{
				h1.add(game_deck.getNext());
			}

			else {
				cout << "move pos\n";
				cin >> loc;
				loc--;
				//just pass hand, location, and top card from pile
				while (!checkMove(h1, loc, pile.top()))
				{
					cout << "not valid move, try again\n";
					cout << "move pos\n";
					cin >> loc;
					loc--;
				}

				h1.removeCard(loc);

			}

			game_state = false;
		}
	}
	cout << endl;
	cout << endl;
	h1.disp();
	cout << endl;

    return 0;
}

Deck * newDeck()
{
	return new Deck();
}

bool checkRange(Hand hand_, int loc_)
{
	return (loc_ >= 0 && loc_ <= hand_.getSize());
}

bool checkMove(Hand hand_, int loc_, Card pile_card)
{
	if (!checkRange(hand_, loc_))
		return false;
	Card player_card = hand_.getCard(loc_);
	//do move, since position is valid
	
	//regular, colored number card
	if (player_card.number != -1)
	{
		if (player_card.number == pile_card.number || player_card.color == pile_card.color)
			return true;
		else
			return false;
	}

	switch (player_card.special == pile_card.special)
		case 0: cout << "LOL";

	return true;
}


/*do
{
cout << "move pos\n";
cin >> loc;
loc--;
if (loc == -1)
{
draw = true;
h1.add(game_deck.getNext());
}
else
{
h1.removeCard(loc);
}
} while (!checkMove(h1, loc, pile.top()) && !draw);*/