#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_match(char a[], char b[], int len) {
	int totalCount = 0;
	
	int i;
	for (i = 0; i < len; i++) {
		if (a[i] == b[i]) {
			totalCount++;
		}
		if (totalCount == len) {
			return 1;
		}
	}
	/* this goes through the two arrays and checks for matches. If theres a
	 * match then totalCount increments by 1. If, at the end, totalCount is 
	 * equal to the length of the int len, then there's a full match. */

	return 0;
}


void read_sig(char arr[]) {
	char gif1[] = {0x47, 0x49, 0x46, 0x38, 0x39, 0x61};
	char gif2[] = {0x47, 0x49, 0x46, 0x38, 0x37, 0x61};
	char elf[] = {0x7f, 0x45, 0x4C, 0x46};
	char pdf[] = {0x25, 0x50, 0x44, 0x46};
	char zip[] = {0x50, 0x4b};
	char jav[] = {0xCA, 0xFE, 0xBA, 0xBE};
	char png[] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A}; 
	char png2[] = {0x89, 0x50, 0x4E, 0x47, 0x1A, 0x0, 0x0, 0x0};
	/* all the possible matches */

	if(check_match(arr, gif1, 6)) {
		printf("This is a GIF file.\n");
		exit(1);
	}
	if(check_match(arr, gif2, 6)) {
		printf("This is a GIF file.\n");
		exit(1);
	}
	if(check_match(arr, elf, 4)) {
		printf("This is an ELF file.\n");
		exit(1);
	}
	if(check_match(arr, pdf, 4)) {
		printf("This is a PDF file.\n");
		exit(1);
	}
	if(check_match(arr, zip, 2)) {
		printf("This is a ZIP file.\n");
		exit(1);
	}
	if(check_match(arr, jav, 4)) {
		printf("This is a Java class file.\n");
		exit(1);
	}
	if(check_match(arr, png, 8)) {
		printf("This is a PNG file.\n");
		exit(1);
	}
	if(check_match(arr, png2, 8)) {
		printf("This is a PNG file.\n");
		/* I was getting the wrong png values using fscanf, and this checked for it. */
		exit(1);
	}
	/* each one of these calls check_match with a different file type, and different
	 * integer value depending on how many bytes are necessary to check for a match. */

	printf("File type unknown.\n");

}

int main(int argc, char *argv[])
{	
	FILE *fp; /* file pointer */
    char arr[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}; /* empty array for values */

	if (argv[1] == NULL) {
		fprintf(stderr, "Invalid input.\n");
		exit(1); /* checks for an input file */
	}
	if (argv[2] != NULL) {
		fprintf(stderr, "Invalid input.\n");
		exit(1); /* checks for 2 inputs */
	}

	fp = fopen(argv[1], "rb");

	if (fp == NULL) {
		fprintf(stderr, "Invalid input.\n");
		exit(1); /* makes sure the file can be opened */
	}

    fread(arr, 1, 8, fp);
    /* Moves the read values from fp and places them into arr.
     * I couldn't get fscanf to work, it worked for everything but PNG.
     * by using fread I coud get it to work perfectly, not sure why. */

	/*    
    fprintf(stderr, "%02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX %02hhX\n", 
    	arr[0], arr[1], arr[2], arr[3], 
    	arr[4], arr[5], arr[6], arr[7]);
	*/

	read_sig(arr); /* check for matches */
	return 0;
}

