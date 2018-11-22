#pragma once
#include "LinkedList.h"
#include <iostream>

class LRUCache
{
public:
	LRUCache();
	~LRUCache();
	bool AddToCache(LinkedList *linkedList);
	std::string GetFromCache(LinkedList *linkedList, int id);
};

