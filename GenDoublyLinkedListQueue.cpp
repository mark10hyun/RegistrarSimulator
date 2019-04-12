#include <iostream> //when working with template classes, declarations and definitions go in the same header file rather than a .cpp file
#include "GenQueueTemp.h"
#include "GenDoublyLinkedListQueue.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"

using namespace std;

	GenDoublyLinkedListQueue::GenDoublyLinkedListQueue()
	{
		nSize = 128;
		numElements = 0;
		head = 0;
		tail = -1;

		myQueue = GenDoublyLinkedList <int> ();
		qu = &myQueue;
	}

	GenDoublyLinkedListQueue::GenDoublyLinkedListQueue(int size)
	{
		nSize = 128;
		numElements = 0;
		head = 0;
		tail = -1;
	}

	GenDoublyLinkedListQueue::~GenDoublyLinkedListQueue()
	{
		delete qu;
	}

	void GenDoublyLinkedListQueue::insert(int d, int d2, int d3)
	{
		qu->insertBack(d, d2,d3);
		numElements++;
		tail++;
	}



	int GenDoublyLinkedListQueue::front()
	{
		return qu->front();
	}

	int GenDoublyLinkedListQueue::front2()
	{
		return qu->front2();
	}

	int GenDoublyLinkedListQueue::remove()
	{
		head++;
		if(head == nSize)
		{
			head = 0;
		}
		numElements--;
		return qu->removeFront();
	}

	int GenDoublyLinkedListQueue::Sum3rd()
	{
		return qu->Sum3();
	}

	int GenDoublyLinkedListQueue::getSize()
	{
		return qu->getSize();
	}

	void GenDoublyLinkedListQueue::AddOneToAll()
	{
		qu->AddToAll();
	}

	bool GenDoublyLinkedListQueue::d2NotEmpty()
	{
		return qu->d2NotEmptyy();
	}

	bool GenDoublyLinkedListQueue::d2Empty()
	{
		return qu->d2Emptyy();
	}

	int GenDoublyLinkedListQueue::getd2(int target)
	{
		return qu->findd2data(target);
	}

	void GenDoublyLinkedListQueue::remove0(int target)
	{
		head++;
		if(head == nSize)
		{
			head = 0;
		}
		numElements--;
		qu->remove(target);
	}

	void GenDoublyLinkedListQueue::Sub_(int count, int time)
	{
		qu->Subtract(count, time);
	}

