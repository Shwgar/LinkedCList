#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
