#pragma once
#include "LinkedList.h"
#include <iostream>
#include <string.h>

class LRUCache
{
public:

	void AddToLinkedList(LinkedList *linkedList, int id,const char *txt);
	std::string ReturnAndSortIfExists(LinkedList *linkedList, int id);
};

