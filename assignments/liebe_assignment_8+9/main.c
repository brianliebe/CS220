#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main() {
	Node two;
	Node one;
	Node four;
	Node three;
	Node * five = (Node *) malloc (sizeof(Node));
	Node * six = (Node *) malloc (sizeof(Node));	

	one.prev = NULL;
	one.next = &two;

	two.prev = &one;
	two.next = &three;

	three.prev = &two;
	three.next = &four;

	four.prev = &three;
	four.next = five;

	five->prev = &four;
	five->next = six;

	six->prev = five;
	six->next = NULL;

	/* printf("%p %p %p\n", &one, &two, &three); */

	Node *temp = sort_nodes(&one);
	if (temp == NULL) {
		printf("null\n");
		exit(1);
	}
	printf("prev: %p current: %p next: %p\n", temp->prev, temp, temp->next);
	while (temp->next != NULL) {
		temp = temp->next;
		printf("prev: %p current: %p next: %p\n", temp->prev, temp, temp->next);
	}
	return 0;
}