#pragma once
#include "LinkedList.h"
#include <iostream>
#include <string.h>
extern "C" void AddToList(LinkedList *linkedList, int id, const char *txt);
extern "C" void DeleteLastFromList(LinkedList *linkedList);


class LRUCache
{
public:

	void AddToLinkedList(LinkedList *linkedList, int id,const char *txt);
	std::string GetAndSort(LinkedList *linkedList, int id);
};

