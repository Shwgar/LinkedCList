#pragma once
#include <stddef.h>
#include <stdlib.h>

struct Node
{
	int id;
	char *txt;
	struct Node *next;
	struct Node *previous;
};

typedef struct
{
	int count;
	struct Node *first;
	struct Node *last;

}LinkedList;

void AddToLinkedList(LinkedList *linkedList, int id, char *txt); //göra dessa i CPP?

struct Node* ReturnAndSortIfExists(LinkedList *linkedList, int id);


