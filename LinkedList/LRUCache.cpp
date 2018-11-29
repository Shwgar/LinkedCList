#include "LRUCache.h"

void LRUCache::AddToLinkedList(LinkedList *linkedList, int id, const char *txt)
{
	if (linkedList->count <10)
	{
		AddToList(linkedList, id, txt);
		linkedList->count = linkedList->count + 1;
	}	
	else if (linkedList->count == 10)
	{
		DeleteLastFromList(linkedList);
		AddToList(linkedList, id, txt);
	}
}

std::string LRUCache::GetAndSort(LinkedList *linkedList, int id)
{
	struct Node *temp = NULL;
	for (int i = 0; i <= linkedList->count-1; i++)
	{
		if (i == 0 && id == linkedList->first->id)
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
				if (id == temp->id && i <= linkedList->count -1)
				{
					temp->previous->next = temp->next;
					if (temp->next != NULL)
					{
						temp->next->previous = temp->previous;
					}
					else if (temp->next == NULL)
					{
						linkedList->last = temp->previous;
					}
					temp->next = linkedList->first;
					linkedList->first->previous = temp;
					temp->previous = NULL;
					linkedList->first = temp;
					return temp->txt;
				}
				temp = temp->next;
			}
		}
	}
	return std::string();
}