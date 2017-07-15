#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int i, val1, val2;
	char oper;
	if (argc != 5) {
		printf("Usage %s <filename> <int> <operation> <int>\n", argv[0]);
		exit(1);
	}

	typedef int (*Calc_fptr)(char, int, int);

	val1 = atoi(argv[2]);
	val2 = atoi(argv[4]);
	oper = *argv[3];
	/* printf("%d %s %d\n", val1, oper, val2); */



	FILE *fp;
	Calc_fptr calculator;

	fp = fopen(argv[1],"rb");
	if (fp == NULL) {
		fprintf(stderr, "Can't open input file!\n");
		exit(1);
	}

	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	unsigned char raw_bytes[sz];

	fread(raw_bytes,sizeof(raw_bytes) * 2,1,fp);
	
	/* 
	for(i = 0; i < sz; i++) {
    	printf("%02x ", raw_bytes[i]);
    } printf("\n");
    */

    calculator = (Calc_fptr) raw_bytes;
    /* calculator('+', 2, 3); */
    printf("%d %c %d = %d\n", val1, oper, val2, calculator(oper, val1, val2));
	return 0;
}