#include <stdio.h>
#include <math.h>

#include "impl_src/macros.h"

int main(int argc, char *argv[]) {
	int value = VALID;
	int value2 = 0x0;
	printf("%x %x %x\n", IS_SET(value2, VALID), IS_SET(value2, DIRTY), IS_SET(value2, USED));	
	SET_BIT(value2, DIRTY);
	printf("%x\n", value2);
	CLEAR_BIT(value2, USED);
	printf("%x\n", value2);
	printf("%d\n", (unsigned int)(log(4*1024)/log(2)));
	int secret = 5;
	int pass;

	printf("Enter pass: ");
	sscanf(argv[1], "%x\n", &pass);
	if (pass != secret) {
		printf(argv[1]);
		printf("is wrong.\n");
	}

	return 0;
}