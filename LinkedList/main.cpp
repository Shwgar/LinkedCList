#include <iostream>
#include "DisplayMessageEndpoint.h"
#include <Windows.h>
#include "LinkedList.h"
#include "LRUCache.h"
#include <cstring>

std::string GetDestinationFrom(int destinationId, LinkedList *linkedList, LRUCache *lruCache)
{
	DisplayMessageDestinationService service;
	std::string returnString = lruCache->GetAndSort(linkedList, destinationId);
	if (returnString != "")
	{
		return returnString;
	}
	else if (returnString == "")
	{
		std::string inputString = service.GetDestinationName(destinationId);
		lruCache->AddToLinkedList(linkedList, destinationId, inputString.c_str());
		return inputString;
	}
}



void main()
{
	LinkedList *linkedList = new LinkedList;
	LRUCache *lruCache = new LRUCache;
	linkedList->count = 0;
	SetConsoleOutputCP(1252);

	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, linkedList, lruCache)
			<< std::endl;
	}
	delete linkedList;
	delete lruCache;
}