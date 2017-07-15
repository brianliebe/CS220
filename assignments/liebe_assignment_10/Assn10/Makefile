all:
	gcc bt.c bt.S -std=c89 -g -o bt
	gcc -c -std=c89 -g -Wall bt.c bt.S -I$PWD
	ar rcs libbt.a bt.o
	gcc -shared -o libbt.so bt.o
