#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf buf;

struct var_state {
	unsigned int * address; 	// address of the variable
	unsigned int size; 			// size of the variable
	unsigned int * data;		// the size of bytes stored at address
	struct var_state * next;	// pointer to next var_state
};
typedef struct var_state var_state;
int g = 10;

#define ARRAY_SIZE 10

var_state *var_state_head = NULL;

void save_state(void *addr, unsigned int size) {
	var_state * temp = (var_state *) malloc (sizeof(var_state));
	temp->address = addr;
	temp->size = size;
	temp->data = (unsigned int *) malloc (size);
	memcpy(temp->data, temp->address, size);
	temp->next = var_state_head;
	var_state_head = temp;
}

void restore_state() {
	/* go through every node    use memcopy*/
	var_state * temp = var_state_head;
	while (temp->next != NULL) {
		memcpy(temp->address, temp->data, temp->size);
		temp = temp->next;
	}
	memcpy(temp->address, temp->data, temp->size);

}

void signal_handler(int a) {
	if (a == SIGSEGV) {
		printf("Inside signal_handler...Segfault\n");
		longjmp(buf, SIGSEGV);
	}
}
/*
void test_saves() {
	var_state * temp = var_state_head;
	while (temp->next != NULL) {
		printf("%d\n", temp->size);
		temp = temp->next;
	}
	printf("%d\n", temp->size);
}
*/
void f() {

	int x;
	char *p;
	x = 11;
	p = (char *) malloc (ARRAY_SIZE);
	p[0] = p[1] = 'x';

	/* Register signal handler for all the signals */
	signal(SIGSEGV, signal_handler);

	/* Save x, g, and p by invoking save_state() on each of them. */
	/* I must save not only p, but also the memory p points to! */ 
	
	save_state(&p, 4);
	save_state(&x, 4);
	save_state(&g, 4);
	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		save_state(&p[i], 1);
	}
	
	if (!setjmp (buf)) {/* fix this, declare the jmp buffer */
	
		g = 30;
		x = 100;
		p = 0;
		p[0] = p[1] = p[2] = 'x';

	} else {
		restore_state();
		printf("%d, %d, %c, %c\n", g, x, p[0], p[1]); 
		/*Expected 10, 11, x, x */
		
	}
	
}

int main (int argc, char *argv[]) {
	f();
	return 0;
}