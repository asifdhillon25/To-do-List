#include <iostream>
using namespace std;
#include "List.h"

void end();
int main() {
	//default Master Key is 0000

	List Mylist;
	char choice;

	do {
		system("cls");
		cout << "\n\n\t  Main Menu\n\n";
		cout << "\t1: Add New Task\n\n"
			<< "\t2: Modify Task\n\n"
			<< "\t3: Show All Tasks\n\n"
			<< "\t4: Set Task Status\n\n"
			<< "\t5: Delete A Task\n\n"
			<< "\t6: Remove Full List\n\n"
			<< "\t7: Exit\n";

		cout << "\n\tEnter your choice: ";
		cin >> choice;
		system("cls");
		int ID = 0;
		switch (choice) {
		case '1':
			Mylist.AddTask();
			break;
		case '2':
			Mylist.ShowTasks();
			cout << "\n\n\nEnter Id of Task\n";
			cin >> ID;
			Mylist.ModifyTask(ID);
			break;
		case '3':
			
			Mylist.ShowTasks();
			break;
		case '4':
			Mylist.ShowTasks();
			cout << "\n\n\nEnter Id of Task\n";
			cin >> ID;
			Mylist.SetStatus(ID);
			break;
		case '5':
			Mylist.ShowTasks();
			cout << "\n\n\n\Enter Id of Task\n";
			cin >> ID;
			Mylist.DeleteTask(ID);
			break;
		case '6':
			Mylist.RemoveAll();
			break;
		
		case '7':
			end();
			break;
		default:
			cout << "INVALID INPUT!!!!\n";
			cout << "\a";
		}
		system("pause");
		system("cls");
	} while (choice != '7');
}

void end() {
	cout << "Thanks for using my code\n"
		<< "Made by Muhammad Asif\n"
		<< "email: asifdhillon25@gmail.com\n"
		<< "Phone: +923166588770\n";
}
