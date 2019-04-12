#pragma once
#include <iostream> //when working with template classes, declarations and definitions go in the same header file rather than a .cpp file
#include "GenQueueTemp.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"

using namespace std;

class GenDoublyLinkedListQueue: public GenQueueTemp <int>
{
public:

	GenDoublyLinkedList <int> myQueue;
	GenDoublyLinkedList<int>* qu;

	GenDoublyLinkedListQueue();
	GenDoublyLinkedListQueue(int size);
	~GenDoublyLinkedListQueue();
	

	void insert(int d, int d2, int d3);
	int front();
	int front2();
	int remove();
	int Sum3rd();
	int getSize();
	void AddOneToAll();
	bool d2NotEmpty();
	bool d2Empty();
	int getd2(int target);
	void remove0(int target);
	void Sub_(int count, int time);
};