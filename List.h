#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Tasks.h"
using namespace std;
class List
{
public:

	void AddTask();
	void ModifyTask(int Id);
	void DeleteTask(int Id);
	void ShowTasks();
	void RemoveAll();
	void SetStatus(int Id);
	bool checkSamekey(int ID);


		
};

