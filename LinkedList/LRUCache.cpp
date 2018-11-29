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

void LRUCache::MoveToFront(LinkedList *linkedList, Node *node)
{
	
	node->previous->next = node->next;
	if (node->next != NULL)
	{
		node->next->previous = node->previous;
	}
	else if (node->next == NULL)
	{
		linkedList->last = node->previous;
	}
	node->next = linkedList->first;
	linkedList->first->previous = node;
	node->previous = NULL;
	linkedList->first = node;
}

std::string LRUCache::Get(LinkedList *linkedList, int id)
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
					MoveToFront(linkedList, temp);
					return temp->txt;
				}
				temp = temp->next;
			}
		}
	}
	return std::string();
}