#include "List.h"
#include<conio.h>
#include<dos.h>
void List::AddTask()
{
	fstream logfile("logfile.dat", ios::out | ios::binary | ios::app);
	if (!logfile)
	{
		cout << "ERROR! in opening file\n";
		return;
	}

	Tasks task; //object of task class;
	task.AddTask();
	if (checkSamekey(task.GetId()))
	{
		cout << "Task exist with same id\n\a";
		cout << "Please change id\n";
		logfile.close();
		return;
	}

	logfile.write(reinterpret_cast<char*>(&task), sizeof(task));
	cout << "Task Added\n";
	logfile.close();
}

void List::ModifyTask(int Id)
{
	fstream logfile("logfile.dat", ios::out | ios::in | ios::binary);
	if (!logfile)
	{
		cout << "ERROR! in opening file\n";
		return;
	}

	Tasks task; //object of task class;
	bool flag = true;//to check if task is present

	while (logfile.read(reinterpret_cast<char*>(&task), sizeof(task)) && flag)
	{
		if (task.GetId() == Id)
		{
			task.ModifyTask();
			int pos = -1 * static_cast<int>(sizeof(task));
			logfile.seekp(pos, ios::cur);
			logfile.write(reinterpret_cast<char*>(&task), sizeof(task));
			flag = false;
		}
	}
	logfile.close();
	if (flag)
	{
		cout << "NO task with this ID\n";
	}
	else
	{
		cout << "Task Modified\n";
	}
}

void List::DeleteTask(int Id)
{
	ifstream logfile;
	ofstream TempFile;

	TempFile.open("Temp.dat", ios::binary);
	logfile.open("logfile.dat", ios::binary);
	if (!logfile || !TempFile)
	{
		cout << "Error! File not open " << endl;
		return;
	}

	Tasks task; //object of task class;

	while (logfile.read(reinterpret_cast<char*>(&task), sizeof(task)))
	{
		if (task.GetId() != Id)
		{
			TempFile.write(reinterpret_cast<char*>(&task), sizeof(task));
		}
	}

	logfile.close();
	TempFile.close();

	remove("logfile.dat");
	rename("Temp.dat", "logfile.dat");
	cout << "\nThis record has been Deleted\n";
}

void List::ShowTasks()
{
	fstream logfile("logfile.dat", ios::out | ios::in | ios::binary);
	if (!logfile)
	{
		cout << "ERROR! in opening file\n";
		return;
	}

	int count = 1;
	Tasks task; //object of task class;
	cout << "======================================================================\n";
	cout << "#no   Id     Task                                               Status\n";
	cout << "======================================================================\n";
	while (logfile.read(reinterpret_cast<char*>(&task), sizeof(task)))
	{
		task.ShowTask(count);
		count++;
	}

	logfile.close();
}

void List::RemoveAll()
{
	cout << "Are You Sure??  Y/N:  ";
	char choice;
	choice = getchar();
	cin >> choice;
	if (choice == 'n' || choice == 'N')
	{
		return;
	}

	if (remove("logfile.dat"))
	{
		cout << "data has been removed\a\n";
	}
	else
	{
		cout << "error in removing\n";
	}
}

void List::SetStatus(int Id)
{
	fstream logfile("logfile.dat", ios::out | ios::in | ios::binary);
	if (!logfile)
	{
		cout << "ERROR! in opening file\n";
		return;
	}

	Tasks task; //object of task class;
	bool flag = true;//to check if task is present

	while (logfile.read(reinterpret_cast<char*>(&task), sizeof(task)) && flag)
	{
		if (task.GetId() == Id)
		{
			task.SetStatus();
			int pos = -1 * static_cast<int>(sizeof(task));
			logfile.seekp(pos, ios::cur);
			logfile.write(reinterpret_cast<char*>(&task), sizeof(task));
			flag = false;
		}
	}
	logfile.close();
	if (flag)
	{
		cout << "NO task with this ID\n";
	}
	else
	{
		cout << "Status Set\n";
	}
}

bool List::checkSamekey(int ID)
{
	bool flag = false;
	Tasks obj;
	fstream Datafile;
	Datafile.open("logfile.dat", ios::in | ios::binary);
	if (!Datafile)
	{
		cout << "Error! File not open " << endl;
		return 0;
	}

	while (Datafile.read(reinterpret_cast<char*>(&obj), sizeof(obj)) && !flag)
	{
		if (obj.GetId() == ID)
		{
			flag = true;
		}
	}

	Datafile.close();
	return flag;
}