#include <iostream> 
#include "GenQueueTemp.h"
#include "GenDoublyLinkedList.h"
#include "DoublyNode.h"
#include "GenDoublyLinkedListQueue.h"
#include "WindowManager.h"

using namespace std;

//I want each window node to be instantiated with 0 idle time
//how do i insert a window node? How do I get the 5 windows to hold idle time

WindowManager::WindowManager(int windows)
{
	num_of_windows = windows;
	total_time_open = 0; //idle time

	GenDoublyLinkedListQueue(); 

	for (int i = 0; i < num_of_windows; i++)
	{
		insert(0,0,0);//etx,mnx,it
	}
}

WindowManager::~WindowManager()
{
	//~GenDoublyLinkedListQueue();
}

/*int WindowManager::getTotalIdleTime()
{
	return Sum();
}*/

int WindowManager::getNumOfWindows()
{
	return num_of_windows;
}
