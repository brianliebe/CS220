#include <stdio.h>
#include <stdlib.h>


struct _Node {
	union {
		int n;
		char c;
	} val;

	void *ptr; 
	
	/* ptr points to the ptr variable in the 
	next node and NOT the beginning of the Node */
	
	int var;
};
typedef struct _Node Node;


Node *my_reverse(Node *head) {
	
	int sum = 0;
	Node *temp = head;
	Node *temp1 = head;
	Node *saveHead = head;

	while (temp->ptr !=NULL) {
		/* printf("%d -> ", head->var); */
		temp = (Node *)(head + 2);
		head = temp;
		sum++;
	}
	/* printf("\nsum: %d\n\n", sum); */

	int tempSum = sum;

	temp1 = (Node *)(saveHead + (sum * 2));

	while (sum > 0) {
		Node *temp2 = (Node *)(saveHead + ((sum-1) * 2));
		temp1->ptr = &temp2->ptr;
		temp1 = temp2;

		/* printf("%d -- ", temp1->var); */

		sum--;
	}
	/* 
	Node *done = (Node *) malloc (sizeof(Node));
	*/
	Node *done = NULL;

	temp1->ptr = NULL;

	Node *returnNode;
	if (tempSum <= 2) {
		returnNode = (Node *)(saveHead + ((tempSum) * 2));
	} else {
		returnNode = (Node *)(saveHead + ((tempSum - 1) * 2));
	}


	return returnNode;

}