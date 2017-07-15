#ifndef _SORTER_H
#define _SORTER_H

struct _Node {
	struct _Node *next;
	struct _Node *prev;
};
typedef struct _Node Node;

Node *sort_nodes(Node *head);

#endif