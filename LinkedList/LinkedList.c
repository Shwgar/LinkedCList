#include "LinkedList.h"

void AddToLinkedList(LinkedList *linkedList, int id, char *txt)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->id = id;
	newNode->txt = txt;

	if (linkedList->count == 0) //Om listan är tom
	{
		newNode->next = NULL;
		newNode->previous = NULL;
		linkedList->first = newNode;
		linkedList->last = newNode;
		linkedList->count = linkedList->count + 1;
	}
	else if (linkedList->count < 10) //Om listan inte är tom men inte full
	{
		linkedList->first->previous = newNode; //sätt prev på den som var först innan till den nya första
		newNode->next = linkedList->first; //sätt nya nodens nästa till förra första
		linkedList->first = newNode; //sätt första till nya noden
		linkedList->count = linkedList->count + 1;
	}
	else if (linkedList->count == 10) //om listan är full
	{
		linkedList->last = linkedList->last->previous;
		free(linkedList->last->next);
		linkedList->last->next = NULL;
		newNode->next = linkedList->first;
		linkedList->first->previous = newNode;
		linkedList->first = newNode;
	}
}

struct Node* ReturnAndSortIfExists(LinkedList *linkedList, int id) //Kolla om ID finns och Node pekaren
{
	struct Node *temp = NULL;
	for (int i = 0; i < linkedList->count-1; i++)
	{
		if (id == linkedList->first->id)
		{
			return linkedList->first;
		}
		else
		{
			if (i == 0)
			{
				temp = linkedList->first->next;
			}
			else
			{
				if (id == temp->id)
				{
					temp->previous->next = temp->next;
					if (temp->next != NULL)
					{
						temp->next->previous = temp->previous;
					}
					linkedList->first = temp;
					return temp;
				}
				temp = temp->next;
			}

		}
	}
	return 0;
}