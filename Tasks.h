#pragma once
#include<iostream>
#include <iomanip>
#include<string>

using namespace std;

class Tasks
{
	char task[200];
	char status[15]="uncompleted";
	int Id;
public:
	Tasks();
	void AddTask();
	int &GetId();
	void SetId(int id);
	void ModifyTask();
	void SetStatus();
	void ShowTask(int count);


};

