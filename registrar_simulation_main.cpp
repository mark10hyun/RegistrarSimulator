#include "auxiliary.h"
#include "DoublyNode.h"
#include "GenDoublyLinkedList.h"
#include "GenDoublyLinkedListQueue.h"
#include "GenQueueTemp.h"
#include "WindowManager.h"
#include "StudentBody.h"

using namespace std;

int total_students;
int time_ = 0;
int clock_tick = 1;
int count_of_registers = 0;
int occupied_registers = 0;

int main(int argc, char* argv[])
{
	string temp = argv[1];
	vector <int> sim_vector = ReadFile(argv[1]);
	vector<int> student_idle_time;

	GenQueueTemp <int> student_enter_times = EnterTimesQ(sim_vector);
	GenQueueTemp <int> number_of_students = NumOfStudentsQ(sim_vector);
	GenQueueTemp <int> students_minutes_needed = StudentsQ(sim_vector);

	GenQueueTemp <int> number_of_students2 = NumOfStudentsQ(sim_vector);

	total_students = TotalStudents(sim_vector);

	//WindowManager Registrar = WindowManager(sim_vector[0]);
	StudentBody Students = StudentBody();

	count_of_registers = sim_vector[0]; //5

	vector<int> Registrar;

	for(int i = 0; i < count_of_registers; i++)
	{
		Registrar.push_back(0);
	}

	while(!student_enter_times.isEmpty()) //pushed all students into a queue
	{
		for(int i = 0; i <= number_of_students.front() -1; i++)
		{
			Students.insertStudent(student_enter_times.front(),students_minutes_needed.front(), 0);
			students_minutes_needed.remove();
		}
		number_of_students.remove();
		student_enter_times.remove();
	}

	while(Students.NeedService()) //There is still a student in the queue whose minutes needed to be helped isnt 0 
	{
		time_ += clock_tick; //progress time
		occupied_registers = count_of_registers - number_of_students2.front(); //number of register that are going to be occupied

		if(Students.FinishedServing())//a students minutes_needed hits 0
		{
			student_idle_time.push_back(Students.getIdleTime()); //push their idle time into idle time vector
			Students.remove0(0); //remove the student who has a minutes_needed as 0 out of the queue
		}

		Students.Sub_(occupied_registers, time_); //subtracts a 1 from all the students in the queue whose time entered is less than 
												 //the current time based of how many occupied registers there are


		cin.get();
	}

	return 0;
}