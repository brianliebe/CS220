#ifndef _POKER_H
#define _POKER_H

enum Suit {
	HEART = 0,
	SPADE,
	CLUB,
	DIAMOND
};

enum Value {
	Two = 0,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

struct card {
	enum Value val;
	enum Suit suit;
};

struct player {
	struct card cards[5]; /* 5 cards for each player */
	unsigned int card_count[13]; /* counters for each of the 13 cards */
	unsigned int vector[56]; /* A bit vector that represents the hand. Bit vector represented by higher hand is larger than bit vector represented by lower hand. */
};

/* TASK 15:
 * Insert declarations for functions in poker.c here.
 */
struct card parse(const char *card);
void count_cards(struct player *p);
int is_flush(struct player *p);
int is_straight(struct player *p);
int is_full_house(struct player *p) ;
int is_straight_flush(struct player *p);
void eval_strength(struct player *p);
void compare_hands(FILE *fp);




#endif
