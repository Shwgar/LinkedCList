#include "LinkedList.h"
//make Node
/*struct Node* newNode = new struct Node();
newNode->id = id;
newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
strcpy(newNode->txt, txt);*/

//Add to list
//kolla om listan �r tom
//l�gg till i listan l�ngst fram
//

void AddToList(LinkedList *linkedList, int id, const char *txt)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->id = id;
	newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newNode->txt, txt);

	if (linkedList->count == 0) //Om listan �r tom
	{
		newNode->next = NULL;
		newNode->previous = NULL;
		linkedList->first = newNode;
		linkedList->last = newNode;

	}
	else
	{
		linkedList->first->previous = newNode; //s�tt prev p� den som var f�rst innan till den nya f�rsta
		newNode->next = linkedList->first; //s�tt nya nodens n�sta till f�rra f�rsta
		linkedList->first = newNode; //s�tt f�rsta till nya noden

	}
}

void DeleteLastFromList(LinkedList *linkedList)
{
	linkedList->last = linkedList->last->previous;
	free(linkedList->last->next->txt);
	linkedList->last->next->previous = NULL;
	free(linkedList->last->next);
	linkedList->last->next = NULL;
}