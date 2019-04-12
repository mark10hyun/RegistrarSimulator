#include <iostream> 
#include "GenQueueTemp.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"
#include "GenDoublyLinkedListQueue.h"
#include "StudentBody.h"

using namespace std;

StudentBody::StudentBody()
{
	count_students = 0;
	total_time_waited = 0;
	enter_time = 0;

	GenDoublyLinkedListQueue();
}

StudentBody::StudentBody(int enter)
{
	count_students = 0;
	total_time_waited = 0;
	enter_time = enter;

	GenDoublyLinkedListQueue();

}

StudentBody::~StudentBody()
{
	//~GenDoublyLinkedListQueue();
}

int StudentBody::getCountOfStudents()
{
	return count_students;
}

int StudentBody::getTotalTimeWaited()
{
	return total_time_waited;
}

int StudentBody::getEnterTime()
{
	return enter_time;
}

void StudentBody::insertStudent(int enter_time, int time_needed, int idle_time)
{
	insert(enter_time, time_needed, idle_time);
	count_students++;
}

bool StudentBody::NeedService()
{
	return d2NotEmpty();
}

bool StudentBody::FinishedServing()
{
	return d2Empty();
}

int StudentBody::getIdleTime()
{
	return getd2(0);
}
