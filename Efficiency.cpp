//--------------------------------
//-- Efficiency By zyf722
//-- A Simple CLI TO-DO Manager
//--------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> toDoList;

vector<string> readList();
void showList(vector<string> l);
void writeList(vector<string> l);

void Add();
void Change();
void Delete();
void Import();
void Export();

int main()
{
	toDoList = readList();
	start:
	while (true)
	{
		cout << endl << " [+] Efficiency TO-DO Manager" << endl;
		showList(toDoList);
		cout << endl << " [+] 1) Add      /      2) Change";
		cout << endl << " [+] 3) Delete   /      4) Import";
		cout << endl << " [+] 5) Export";
		cout << endl << endl << " [!] Please make a choice: ";
		int c;
		cin >> c;
		switch(c)
		{
			case 1: Add(); system("cls"); break;
			case 2: Change(); system("cls"); break;
			case 3: Delete(); system("cls"); break;
			case 4: Import(); system("cls"); break;
			case 5: Export(); system("cls"); break;
			default: system("cls"); goto start;
		}
	}
	return 0;
}

vector<string> readList()
{
	vector<string> l;
	string line;
	ifstream fin("ToDoList.db");
	if (fin)
	{
		while (getline (fin, line))
            l.push_back(line);
	}
	fin.close();
	return l;
}

void showList(vector<string> l)
{
	if (l.size() == 0)
		return;
	else
	{
		cout << endl;
		for (int i=0;i<l.size();i++)
		{
			cout << " ["+to_string(i+1)+"] "+l[i] << endl;
		}
	}
}

void writeList(vector<string> l)
{
	ofstream fout("ToDoList.db");
	for (int i=0;i<l.size();i++)
    {
    	fout << l[i] << endl;
	}
	fout.close();
}

void Add()
{
	string c;
	cin.sync();
	cout << endl << " [!] Please enter the content: ";
	getline(cin,c);
	toDoList.push_back(c);
}

void Change()
{
	int n = 0;
	string c;
	cin.sync();
	cout << endl << " [!] Please enter the number of the content: ";
	cin >> n;
	n -= 1;
	if (n >= toDoList.size() || n < 0)
	{
		cout << endl << " [!] Invalid number!";
		cin.get();
		cin.get();
		return;
	}
	else
	{
		cout << endl << " [!] Please enter the content: ";
		cin.sync();
		getline(cin,c);
		toDoList[n] = c;
	}
}

void Delete()
{
	int n = 0;
	cin.sync();
	cout << endl << " [!] Please enter the number of the content: ";
	cin >> n;
	n -= 1;
	if (n >= toDoList.size() || n < 0)
	{
		cout << endl << " [!] Invalid number!";
		cin.get();
		cin.get();
		return;
	}
	else
	{
		auto iter = toDoList.erase(begin(toDoList)+n);
	}
}

void Import()
{
	toDoList = readList();
	cout << endl << " [+] Done.";
	cin.get();
	cin.get();
}

void Export()
{
	writeList(toDoList);
	cout << endl << " [+] Done.";
	cin.get();
	cin.get();
}
