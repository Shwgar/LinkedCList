#include <iostream>
#include "DisplayMessageEndpoint.h"
#include <Windows.h>
#include "LinkedList.h"
#include "LRUCache.h"
#include <cstring>

std::string GetDestinationFrom(int destinationId, LinkedList *linkedList)
{
	LRUCache *lruCache = new LRUCache;
	DisplayMessageDestinationService service;
	std::string returnString = lruCache->ReturnAndSortIfExists(linkedList, destinationId);
	if (returnString != "")
	{
		return returnString;
	}
	else if (returnString == "")
	{
		std::string inputString = service.GetDestinationName(destinationId);
		//const char *txt = &inputString[0u];
		lruCache->AddToLinkedList(linkedList, destinationId, inputString.c_str());
		return inputString;
	}

	//DisplayMessageDestinationService service;
	//return service.GetDestinationName(destinationId);
	//This call is really slow!!!

	//Uppgift: Skapa en LRU cache...
	//Du f�r dock spara h�gst 10 st f�r det finns s� lite minne i displayen

	//1. Skapa en C-only linkedlist - varf�r? - den ska anv�ndas i en c-only device senare.. 
	//struct Node
	//{
	//	int id;
	//	char *txt;
	//	struct Node *next;
	//};
	//kom ih�g att malloc och free p� b�de noder och char *

	//2. Anropa denna h�rifr�n sas
	// if linkedlist_get(id) == NULL
	//{
	//fetch from remote service.GetDestinationName(destinationId)
	//	Add to linked list (FRONT)
	//	Ta bort sista om > 10!
	//}
	//else if linkedlist_get(id) != NULL
	//	Move it to FRONT!
	//
}



void main()
{
	LinkedList *linkedList = new LinkedList;
	linkedList->count = 0;
	SetConsoleOutputCP(1252);

	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, linkedList)
			<< std::endl;
	}
}