#include "prog.h"

int nthFib(int n)
{
	/* 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 etc
	 * this assumes that n wants the nth number, so if n = 5 then it wants the 5th number, and 0th is skipped. */

	if ((n < 1) || (n >30)) return -1;
	if (n == 1) return 0;
	if (n == 2) return 1;

	int a = 0;
	int b = 1;
	int c = 0;

	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n -= 1;
	}

	return c; 
}

int asq_minus_bsq(int a, int b) 
{
	return (a * a) - (b * b);
}
