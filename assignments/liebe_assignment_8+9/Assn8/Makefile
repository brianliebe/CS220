all:
	gcc estimator.c estimator.S -std=c89 -g -o estimator
	gcc -c -std=c89 -g -Wall sorter.c -I$PWD
	ar rcs libsort.a sorter.o
	gcc -shared -o libsort.so sorter.o
