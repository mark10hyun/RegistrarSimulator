#pragma once
#include <iostream>

using namespace std;

template <class any_type>

class GenQueueTemp
{

public:
	int nSize;
	int head;
	int tail;
	int numElements;
	any_type* myQueue; //array

public:

	GenQueueTemp()
	{
		myQueue = new any_type[128];
		nSize = 128;
		numElements = 0;
		head = 0;
		tail = -1;
	};

	GenQueueTemp(any_type maxSize)
	{
		myQueue = new any_type[maxSize];
		nSize = maxSize;
		numElements = 0;
		head = 0;
		tail = -1;
	};

	virtual ~GenQueueTemp()
	{
		myQueue = NULL;
		delete myQueue;
		//cout <<"\nQueue Deleted\n";
	};

	void insert(any_type d)//Enqueue push
	{
		//error checking bounds/isfull
		//circular code

		if(tail == nSize-1)
		{
			tail = -1;
		}

		myQueue[tail++] = d;
		numElements++;
	}; 

	any_type remove() //Dequeue pop
	{
		//error checking bounds/isempty
		//circular code

		any_type temp;
		temp = myQueue[head];
		head++;


		if(head == nSize)
		{
			head = 0;
		}


		numElements--;

		return temp;
	}; 

	any_type front()  //aka peek
	{
		return myQueue[head-1];
	}; 

	bool isFull()
	{
		return (numElements == nSize);
	};

	bool isEmpty()
	{
		return (numElements == 0);
	};

	int getSize()
	{
		return numElements;
	};

	void Print()
	{
		for(int i = head-1; i <= tail-1; i++)
		{
			if(i != tail -1)
			{
				cout << myQueue[i] << ",";
			}

			else
			{
				cout << myQueue[i] << "\n";
			}
			
		}
	}
};