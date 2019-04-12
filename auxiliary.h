#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GenQueueTemp.h"

using namespace std;

auto Terminal(
	[](auto obj) //[] - lambda introducer, (parameter target)
{
	cout << "\n" << obj << "\n";
}
);

vector <int> ReadFile(string my_file);
void PrintVector(vector<int> to_print);
int TotalTime(vector<int> my_vector);
int TotalStudents(vector<int> my_vector);
vector <int> EnterTimes(vector<int> my_vector);


GenQueueTemp <int> EnterTimesQ(vector<int> my_vector);
GenQueueTemp <int> StudentsQ(vector<int> my_vector);
GenQueueTemp <int> NumOfStudentsQ(vector<int> my_vector);
//int TotalTimeOpen();