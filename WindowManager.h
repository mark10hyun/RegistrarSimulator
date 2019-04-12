#pragma once
#include <iostream>
#include "GenQueueTemp.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"
#include "GenDoublyLinkedListQueue.h"


using namespace std;

class WindowManager: public GenDoublyLinkedListQueue
{
public:
	int num_of_windows;
	int total_time_open;
	int total_idle_time;

public:
	WindowManager(int windows);
	~WindowManager();

public:
	int getNumOfWindows();
	int getTotalIdleTime();
};