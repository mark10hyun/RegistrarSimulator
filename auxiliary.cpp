#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "auxiliary.h"
#include "GenQueueTemp.h"


using namespace std;

vector <int> ReadFile(string my_file)
{
	ifstream inFileStream;
	int number;
	vector <int> temp;

	inFileStream.open(my_file);
	
	while (!inFileStream.eof()) 
	{
		inFileStream >> number;
		temp.push_back(number);
	}
	inFileStream.close();

	return temp;
}

void PrintVector(vector<int> to_print)
{
	for(int i = 0; i < to_print.size(); i++)
	{
		Terminal(to_print[i]);
	}
}

int TotalTime(vector<int> my_vector)
{
	int total_time = 0;

	int index_students = 2; 
	int index_of_min = index_students+1; //3

	int number_of_student = my_vector[index_students];

	while(true)
	{
		if(number_of_student > 0)
		{
			for(int i = 0; i < number_of_student; i++)
			{
				total_time += my_vector[index_of_min + i];
			}

			if(index_students+number_of_student+2 < my_vector.size())
			{
				index_students += number_of_student+2;
				index_of_min = index_students+1;
				number_of_student = my_vector[index_students];
			}
			else
			{
				return total_time;
			}
		}
	}
}

int TotalStudents(vector<int> my_vector)
{
	int total_students = 0;

	int index_students = 2; 
	int number_of_students = my_vector[index_students];

	while(true)
	{
		if(number_of_students > 0)
		{
			if(index_students + number_of_students + 2 < my_vector.size())
			{
				total_students += my_vector[index_students];

				index_students = index_students + number_of_students +2;
				number_of_students = my_vector[index_students];
			}
			else
			{
				return total_students + number_of_students;
			}
		}
	}
}

vector <int> EnterTimes(vector<int> my_vector)
{
	vector <int> enter_times;
	int enter_index = 1;
	int enter_time;

	int index_students = 2; 
	int number_of_students = my_vector[index_students];

	while(true)
	{
		if(number_of_students > 0)
		{
			if(enter_index + number_of_students + 2 <= my_vector.size())
			{
				enter_times.push_back(my_vector[enter_index]);

				enter_index = enter_index + number_of_students + 2;
				index_students = enter_index+1;
				number_of_students = my_vector[index_students];
			}
			else
			{
				//enter_times.push_back(my_vector[enter_index]);
				return enter_times;
			}
		}
	}
}

GenQueueTemp <int> EnterTimesQ(vector<int> my_vector)
{
	GenQueueTemp <int> enter_timesQ = GenQueueTemp <int> (my_vector.size());
	int enter_index = 1;
	int enter_time;

	int index_students = 2; 
	int number_of_students = my_vector[index_students];

	while(true)
	{
		if(number_of_students > 0)
		{
			if(enter_index + number_of_students + 2 <= my_vector.size())
			{
				enter_timesQ.insert(my_vector[enter_index]);

				enter_index = enter_index + number_of_students + 2;
				index_students = enter_index+1;
				number_of_students = my_vector[index_students];
			}
			else
			{
				//enter_times.push_back(my_vector[enter_index]);
				return enter_timesQ;
			}
		}
	}

	return enter_timesQ;
}

GenQueueTemp <int> StudentsQ(vector<int> my_vector)
{
	GenQueueTemp <int> students_Q = GenQueueTemp <int> (my_vector.size());
	int number_of_students_index = 2;
	int student_time_index = 3;

	int student_time_needed;
	int number_of_students = my_vector[number_of_students_index];

	while(true)
	{
		if(number_of_students > 0)
		{
			if(number_of_students_index + number_of_students + 2 <= my_vector.size())
			{
				for(int i = 0; i < number_of_students; i++)
				{
					students_Q.insert(my_vector[student_time_index + i]);
				}

				number_of_students_index = number_of_students_index + number_of_students + 2;
				student_time_index = number_of_students_index + 1;
				number_of_students = my_vector[number_of_students_index];
			}
			else
			{
				//enter_times.push_back(my_vector[enter_index]);
				return students_Q;
			}
		}
	}

	return students_Q;
}

GenQueueTemp <int> NumOfStudentsQ(vector<int> my_vector)
{
	GenQueueTemp <int> num_students_Q = GenQueueTemp <int> (my_vector.size());

	int index_students = 2; 
	int number_of_students = my_vector[index_students];

	while(true)
	{
		if(number_of_students > 0)
		{
			if(index_students + number_of_students + 2 < my_vector.size())
			{
				num_students_Q.insert(my_vector[index_students]);

				index_students = index_students + number_of_students +2;
				number_of_students = my_vector[index_students];
			}
			else
			{
				num_students_Q.insert(my_vector[index_students]);
				return num_students_Q;
			}
		}
	}

	return num_students_Q;
}

/*int TotalTimeOpen()
{
	int total_time_open;

	return total_time_open;
}*/