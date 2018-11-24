#include "LinkedList.h"
//make Node
/*struct Node* newNode = new struct Node();
newNode->id = id;
newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
strcpy(newNode->txt, txt);*/

//Add to list
//kolla om listan är tom
//lägg till i listan längst fram
//

void AddToList(LinkedList *linkedList, int id, const char *txt)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->id = id;
	newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newNode->txt, txt);

	if (linkedList->count == 0) //Om listan är tom
	{
		newNode->next = NULL;
		newNode->previous = NULL;
		linkedList->first = newNode;
		linkedList->last = newNode;

	}
	else
	{
		linkedList->first->previous = newNode; //sätt prev på den som var först innan till den nya första
		newNode->next = linkedList->first; //sätt nya nodens nästa till förra första
		linkedList->first = newNode; //sätt första till nya noden

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