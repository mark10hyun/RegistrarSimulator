#include "GenQueue.h"
#include <iostream>

using namespace std;

GenQueue::GenQueue()
{
	myQueue = new char[128];
	nSize = 128;
	numElements = 0;
	head = 0;
	tail = -1;
}

GenQueue::GenQueue(int maxSize)
{
	myQueue = new char[maxSize];
	nSize = maxSize;
	numElements = 0;
	head = 0;
	tail = -1;
}

GenQueue::~GenQueue()
{
	myQueue = NULL;
	delete myQueue;
	cout <<"\nQueue Deleted\n";
}

void GenQueue::insert(char d)
{
	//error checking bounds/isfull
	//circular code

	if(tail == nSize-1)
	{
		tail = -1;
	}

	myQueue[tail++] = d;
	numElements++;
}

char GenQueue::remove()
{
	//error checking bounds/isempty
	//circular code

	char c = '\0';
	c = myQueue[head];
	head++;


	if(head == nSize)
	{
		head = 0;
	}


	numElements--;

	return c;
}

char GenQueue::front()
{
	return myQueue[head-1];
}

bool GenQueue::isFull()
{
	return (numElements == nSize);
}

bool GenQueue::isEmpty()
{
	return (numElements == 0);
}

int GenQueue::getSize()
{
	return numElements;
}