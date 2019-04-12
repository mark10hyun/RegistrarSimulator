#pragma once
#include <iostream>
#include "GenQueueTemp.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"
#include "GenDoublyLinkedListQueue.h"


using namespace std;

class StudentBody: public GenDoublyLinkedListQueue
{
public:
	int count_students;
	int total_time_waited;
	int enter_time;

public:
	StudentBody();
	StudentBody(int enter);
	
	~StudentBody();

public:
	int getCountOfStudents();
	int getTotalTimeWaited();
	int getEnterTime();
	void insertStudent(int enter_time, int time_needed, int idle_time);
	bool NeedService();

	bool FinishedServing();
	int getIdleTime();	
};