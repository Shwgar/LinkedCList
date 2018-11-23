#define ForI(l) for(int i = 0, i < l, i++)
#include "LRUCache.h"

void LRUCache::AddToLinkedList(LinkedList *linkedList, int id, const char *txt)
{

	struct Node* newNode = new struct Node();
	newNode->id = id;
	//strcpy(newNode->txt, txt);
	newNode->txt = (char*)malloc(sizeof(char) * strlen(txt) + 1);
	strcpy(newNode->txt, txt);
	

	if (linkedList->count == 0) //Om listan �r tom
	{
		newNode->next = NULL;
		newNode->previous = NULL;
		linkedList->first = newNode;
		linkedList->last = newNode;
		linkedList->count = linkedList->count + 1;
	}
	else if (linkedList->count < 10) //Om listan inte �r tom men inte full
	{
		linkedList->first->previous = newNode; //s�tt prev p� den som var f�rst innan till den nya f�rsta
		newNode->next = linkedList->first; //s�tt nya nodens n�sta till f�rra f�rsta
		linkedList->first = newNode; //s�tt f�rsta till nya noden
		linkedList->count = linkedList->count + 1;
	}
	else if (linkedList->count == 10) //om listan �r full
	{
		linkedList->last = linkedList->last->previous;
		free(linkedList->last->next);
		linkedList->last->next = NULL;
		newNode->next = linkedList->first;
		linkedList->first->previous = newNode;
		linkedList->first = newNode;
	}
}

std::string LRUCache::ReturnAndSortIfExists(LinkedList *linkedList, int id) //Kolla om ID finns och Node pekaren
{
	struct Node *temp = NULL;
	for (int i = 0; i < linkedList->count - 1; i++)
	{
		if (id == linkedList->first->id)
		{
			return linkedList->first->txt;
		}
		else
		{
			if (i == 0)
			{
				temp = linkedList->first->next;
			}
			else
			{
				if (id == temp->id && i <= linkedList->count)
				{
					temp->previous->next = temp->next;
					if (temp->next != NULL)
					{
						temp->next->previous = temp->previous;
					}
					linkedList->first = temp;
					return temp->txt;
				}
				temp = temp->next;
			}

		}
	}
	return std::string();
}