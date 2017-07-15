#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *sort_nodes(Node *head) {
	int i, j;
	void * k;
	int sum = 1;

	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return head;
	}

	Node *temp = head;
	while (temp->next != NULL) {
		sum++;
		temp = (Node *)temp->next;
	}
	void * list[sum];

	temp = head;
	for (i = 0; i < sum; i++) {
		list[i] = temp;
		temp = (Node *)temp->next;
	}

	for (i = 0; i < sum; i++)
    {
        for (j = 0; j < (sum - i - 1); j++)
        {
            if (list[j] < list[j + 1])
            {
                k = list[j];
                list[j] = list[j + 1];
                list[j + 1] = k;
            }
        }
    }

	temp = (Node *)list[0];
	temp->prev = NULL;
	temp->next = (Node *)list[1];
	for (i = 1; i < sum - 1; i++) {
		temp = (Node *)list[i];
		temp->prev = (Node *)list[i-1];
		temp->next = (Node *)list[i+1];
	}
	temp = (Node *)list[sum - 1];
	temp->prev = (Node *)list[sum - 2];
	temp->next = NULL;

	/*
    for (i = 0; i < sum; i++) {
		printf("prev: %p current: %p next: %p\n", ((Node *)list[i])->prev, list[i], ((Node *)list[i])->next);
	}
	*/

	return (Node *)list[0];
}
/*
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

	printf("%p %p %p\n", &one, &two, &three);

	Node *temp = sort_nodes(&one);
	printf("prev: %p current: %p next: %p\n", temp->prev, temp, temp->next);
	while (temp->next != NULL) {
		temp = temp->next;
		printf("prev: %p current: %p next: %p\n", temp->prev, temp, temp->next);
	}
	return 0;
}
*/