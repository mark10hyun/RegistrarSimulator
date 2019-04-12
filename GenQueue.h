#pragma once
using namespace std;

class GenQueue
{
public:

	GenQueue();
	GenQueue(int maxSize);
	~GenQueue();

	void insert(char d); //Enqueue push
	char remove(); //Dequeue pop
	char front(); //aka peek
	bool isFull();
	bool isEmpty();
	int getSize();

	int nSize;
	int head;
	int tail;
	int numElements;
	char* myQueue; //array

};