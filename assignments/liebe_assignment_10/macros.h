#ifndef _MACROS_H
#define _MACROS_H

#include <stdio.h>

#define BIT(n) (1 << (n))
#define BIT_SET(v, mask) (v |= (mask))
#define BIT_CLEAR(v, mask) (v &= -(mask))
#define BIT_FLIP(v, mask) (v ^= (mask))
#define IS_SET_ANY(v, mask) (v & (mask))
#define IS_CLEAR_ANY(v, mask) (!(v & (mask))) 

#define BIT_MASK(len) (BIT(len) - 1)
#define BF_MASK(start, len) (BIT_MASK(len)<<(start))
#define BF_PREP(x, start, len) (((x)&BIT_MASK(len)) << (start))
#define BF_GET(y, start, len)  ((y)>>(start) & (BIT_MASK(len)))
#define BF_SET(y, x, start, len) ((y)&~(BIT_MASK(len)<<(start)) | ((x)<<(start)))

#define GET_LEN(start, end) ((end) - (start) + 1)

#define TEST_IF_ANY_SET(v, start, end) ((BF_GET((v), (start), (GET_LEN((start), (end))))) || BIT_MASK(0))
#define TEST_IF_ALL_SET(v, start, end) ((BF_GET((v), (start), (GET_LEN((start), (end))))) == BIT_MASK(GET_LEN((start), (end))))
#define COUNT_NUM_SET(v, start, end)  \
	int count = 0;\
	int test = 0;\
	v = ((BF_GET((v), (start), GET_LEN((start), (end)))));\
	for (test = 0; test < 32; test++) {\
		if (IS_SET_ANY(v, BIT(test))) {\
			count ++;\
		}\
	}\
	printf("%d\n", count);

#endif