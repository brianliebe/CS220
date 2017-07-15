#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

void print_in_binary(unsigned int x) {
	int i;
	for (i = 31; i >= 0; i--) {
		if (IS_SET_ANY(x, BIT(i))) {
			printf("1");
		} else {
			printf("0");
		}
	} 
	printf("\n");
}

int main() {
	unsigned int address = 0xf712c0d0;

	printf("Original:\t\t");
	print_in_binary(address);
	printf("\t\t\t");
	int i = 0; 
	for (i = 31; i >=0; i--) {
		printf("%d", TEST_IF_ALL_SET(address, i - 2, i)); 
	} printf("\n");

	COUNT_NUM_SET(address, 0, 5);
	
	return 0;
}