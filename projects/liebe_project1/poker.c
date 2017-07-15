#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poker.h"

/* Global instances of the two players */
struct player P1, P2;


/* Parse card from a 2 char input */
struct card parse(const char *card)
{
	/* TASK 14: parse input and store in card data structure. */
	struct card c;
	/* printf("%c %c\n", card[0], card[1]); */

	/* printf("%c %c %c\n", *card, card[0], card[1]); */

	switch (card[0]) {
		case '2': c.val = 0; break;
		case '3': c.val = 1; break;
		case '4': c.val = 2; break;
		case '5': c.val = 3; break;
		case '6': c.val = 4; break;
		case '7': c.val = 5; break;
		case '8': c.val = 6; break;
		case '9': c.val = 7; break;
		case 'T': c.val = 8; break;
		case 'J': c.val = 9; break;
		case 'Q': c.val = 10; break;
		case 'K': c.val = 11; break;
		case 'A': c.val = 12; break;
		default: break;
	}

	switch(card[1]) {
		case 'H': c.suit = 0; break;
		case 'S': c.suit = 1; break;
		case 'C': c.suit = 2; break;
		case 'D': c.suit = 3; break;
	}

	/* Hint: You could use switch statements here */
	return c;
}

/* Count the number of occurrences of each card 2 through Ace */
void count_cards(struct player *p)
{
	/* TASK 13:  
	 * Iterate through the cards and increment the counter for each card
	 */
	 int i;
	 for (i = 0; i < 5; i++) {
	 	p->card_count[(p->cards[i]).val]++;
	 }
}

int is_flush(struct player *p)
{
	/* TASK 12:
	 * Hand is flush if suit of all the cards is the same
	 */

	int hearts = 0;
	int spades  = 0;
	int clubs  = 0;
	int diamonds = 0;
	int i;
	for (i = 0; i < 4; i++) {
		/* printf("%d\n", (p->cards[i]).suit); */
		if ((p->cards[i]).suit == 0) {
			hearts++;
		}
		if ((p->cards[i]).suit == 1) {
			spades++;
		}
		if ((p->cards[i]).suit == 2) {
			clubs++;
		}
		if ((p->cards[i]).suit == 3) {
			diamonds++;
		}
	}
	if (hearts == 4 || spades == 4 || clubs == 4 || diamonds == 4) {
		return 1;
	}


	return 0; /* Return 1 if flush */
}

int is_straight(struct player *p)
{
	/* NOTE: By this stage, the vector must be constructed.
	 * 
	 * The hand is a straight, if the cards are sequential.
	 * A2345 as well as TJQKA are both valid straights, and Ace 
	 * assumes the value of 1 or 13, but not both.
	 */

	/* TASK 11: Check for regular straights
 	 * Hint: If this is a straight, player's card_count for i, i+1, i+2, i+3 and i+4 should be 1. */

	 int done = 0;
	 int i;
	 for (i = 0; i < 9 && done == 0; i++) {
	 	if (p->vector[i] == 1 && p->vector[i + 1] == 1 && p->vector[i + 2] == 1 && p->vector[i + 3] == 1 && p->vector[i + 4] == 1) {
	 		done = 1;
	 		return 1;
	 	}
	 }
	/* Check for A2345
	 * TASK 10: If the hand is A2345, reset the bit for highcard Ace in the player's vector to appropriately reflect that the value of A is not 13. 
	 * Hint: 1 << position will generate a bit mask for the position of Ace. Xoring it with the vector will reset the bit.
	 */
	 if (p->vector[0] == 1 && p->vector[1] == 1 && p->vector[2] == 1 && p->vector[3] == 1 && p->vector[12] == 1 ) {
	 	p->vector[12] = 0;
	 	return 1;
	 }

	return 0; /* Return 1 if straight */	
}

int is_full_house(struct player *p) 
{
	/* TASK ?: Detect if there's a fullhouse */ 
	int j;
	int doubles = 0;
	int triples = 0;
	for (j = 0; j < 13; j++) {
		if (p->card_count[j] == 2) {
			doubles = 1;
		}
		if (p->card_count[j] == 3) {
			triples = 1;
		}
	}
	if (doubles == 1 && triples == 1) {
		return 1;
	}
	return 0;
}

int is_straight_flush(struct player *p)
{
	/* TASK 9: Detect straight flush. A straight flush is nothing but a straight and a flush */
	if (is_flush(p) == 1 && is_straight(p) == 1) {
		return 1;
	}


	return 0; /* Return 1 if straight flush */
}
		
/* This is the main function that converts the player's hand into weighted unsigned long number. 
It is a 55bit vector as shown below (2 is the LSB and StraightFlush is the MSB) */
/* 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A, 22, 33, 44, 55, 66, 77, 88, 99, TT, JJ, QQ, KK, AA,
222, 333, 444, 555, 666, 777, 888, 999, TTT, JJJ, QQQ, KKK, AAA, Straight, Flush, FullHouse, 2222, 3333, 
4444, 5555, 6666, 7777, 8888, 9999, TTTT, JJJJ, QQQQ, KKKK, AAAA, StraightFlush */
/* The number of occurrences of each number in the hand is first calculated in count_cards. 
Then, depending on the numeber of occurrences, the corresponding bit in the bit-vector is set. 
In order to find the winner, a simple comparison of the bit vectors (i.e., unsigned long integers) will suffice! */
void eval_strength(struct player *p)
{
	unsigned int straight_or_flush_possible;
	unsigned int i;
	straight_or_flush_possible = 1; 

	/*
	 * TASK 6: Invoke the function to count the occurrences of each card
	 */
	count_cards(p);


	/*
	 * TASK 7: Iterate through the card_count array, and set the appropriate bit in the bit vector.
	 * For example, if the hand is JH JS 3C AH 4H, set the 23rd bit to indicate a pair of jacks, and 2nd, 3rd and 13th bit to indicate 3, 4 and A respectively. */
	
	int j;
	for (j = 0; j < 56; j++) {
		p->vector[j] = 0;
	}

	/* P2.card_count[4] = 2; */
	

	for (j = 0; j < 13; j++) {

		if (p->card_count[j] == 1) {
			p->vector[j] = 1;
		}
		if (p->card_count[j] == 2) {
			p->vector[j + 13] = 1;
		}
		if (p->card_count[j] == 3) {
			p->vector[j + 25] = 1;
		}
		if (p->card_count[j] == 4) {
			p->vector[j + 42] = 1;
		}
	}

	/* TASK 8:
	 * Check if this is a straight, flush or a straight flush, and set the appropriate bit in the vector.
	 */

	 if (is_straight(p)) {
	 	p->vector[39] = 1;
	 }
	 if (is_flush(p)) {
	 	p->vector[40] = 1;
	 }
	 if (is_full_house(p)) {
	 	p->vector[41] = 1;
	 }
	 if (is_straight_flush(p)) {
	 	p->vector[55] = 1;
	 }
}

/* Parse each hand in the input file, evaluate the strengths of hands and identify a winner by comparing the weighted vectors */
void compare_hands(FILE *fp)
{


	char p1[5][3];
	char p2[5][3];
	int i;

	FILE *f = fopen("Output.txt", "w");
	if (f == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}

	while(fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", 
		&p1[0][0], &p1[1][0], &p1[2][0], &p1[3][0], &p1[4][0], 
		&p2[0][0], &p2[1][0], &p2[2][0], &p2[3][0], &p2[4][0]) == 10) {
		memset(&P1, 0, sizeof(struct player));
		memset(&P2, 0, sizeof(struct player));
		for(i = 0; i < 5; i++) {
			P1.cards[i] = parse(&p1[i][0]);
			P2.cards[i] = parse(&p2[i][0]);
		}

		/* TASK 4: Invoke eval_strength for each player */
		eval_strength(&P1);
		eval_strength(&P2);
		
		/*
		int y = 0;
		for (y = 0; y < 56; y++) {
			printf("%d", P1.vector[y]);
		}
		printf("\n");
		y = 0;
		for (y = 0; y < 56; y++) {
			printf("%d", P2.vector[y]);
		}
		*/
		/* TASK 5: Report the winner (e.g., "Player 1 wins") depending on whoever has the higher vector */
		int k;
		int done = 0;
		int winner = 0;
		
		for (k = 55; k >= 0 && done == 0; k--) {
			if (P1.vector[k] > P2.vector[k]) {
				done = 1;
				/* printf("\nPlayer 1 wins\n"); */
				winner = 1;
			}
			if (P2.vector[k] > P1.vector[k]) {
				done = 1;
				/* printf("\nPlayer 2 wins\n"); */
				winner = 2;
			}
		}
		
		if (done == 0) {
			/* printf(" \nNo one wins!\n"); */
			winner = 0;
		}
		char *text = "";
		switch (winner) {
			case 0: text = "No one wins"; break;
			case 1: text = "Player 1 wins"; break;
			case 2: text = "Player 2 wins"; break;
			default: break;
		}
		fprintf(f, "%s\n", text);
		printf("%s\n", text);

	}
	fclose(f);
	fclose(fp);
}

int main(int argc, char *argv[])
{	
	/* TASK 2: Validate command line arguments and try to open the file. Exit on failure. */

	FILE *fp;
	char *mode = "r";
	fp = fopen(argv[1], mode);

	if (fp == NULL) {
		fprintf(stderr, "Can't open the input file!\n");
		exit(1);
	}
	
	/* TASK 3: Invoke the compare hands function */
	compare_hands(fp);
	return 0;
}
	
