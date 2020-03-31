#ifndef CARD_
#define CARD_

enum Color { red, yellow , green , blue , none_c};
enum Special { skip, reverse, plus_2, plus_4, color_change, none_s};

struct Card {
	Color color;
	int number;
	Special special;
};

#endif CARD_