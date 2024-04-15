#include "Tasks.h"

Tasks::Tasks()
{
	Id = 0;
}

void Tasks::AddTask()
{
	cin.ignore();
	cout << "Enter Task To Add: ";
	cin.getline(task, 200);
	cout << "Enter Id (only integers) :  ";
	cin >> Id;
}

int& Tasks::GetId()
{
	return Id;
}

void Tasks::SetId(int id)
{
	Id = id;
}

void Tasks::ModifyTask()
{
	cin.ignore();
	cout << "Enter new statement for Task To Add: ";
	cin.getline(task, 200);
}

void Tasks::SetStatus()
{
	int choice = 0;
	do
	{
		cout << "Press 1 for Complete\n"
			<< "Press 2 for Uncomplete\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string a = "Complete";

			for (int i = 0; i < a.size(); i++)
			{
				status[i] = a[i];
			}
		}
		break;
		case 2:
		{
			string a = "Uncomplete";

			for (int i = 0; i < a.size(); i++)
			{
				status[i] = a[i];
			}
		}
		break;
		default:
			cout << "Invalid Input!!!";
			break;
		}
		system("pause");
		system("cls");
	} while (choice != 1 && choice != 2);
}

void Tasks::ShowTask(int count)
{
	cout << count << "    " << left << setw(7) << Id << setw(50) << task << setw(20) << status << endl;
}