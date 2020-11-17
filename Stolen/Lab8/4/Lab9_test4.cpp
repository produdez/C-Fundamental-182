#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
struct Info {
	string name;
	int ID, salary;
};
int change(string a)
{
	int x = 0;
	for (int i = 0; i < a.length(); i++)
		for (int j = 48; j < 58; j++)
			if (a[i] == j)
			{
				x = x * 10 + ((char)j - 48);
				break;
			}
	return x;
}
void process(const char* fileName) {
	ifstream fileIO;
	fileIO.open(fileName);
	int n = 0, f, p;
	Info b;
	string line, cop;
	Info student[50];
	while (!fileIO.eof())
	{
		cop = "";
		f = 1;
		getline(fileIO, line);
		for (int i = 0; i < line.length(); i++)
		{
			if (f == 1)
			{
				if (line[i] != ',')
					student[n].name += line[i];
				else
					f++;
			}
			else
			{
				if (f == 2)
				{
					if (line[i] != ',')
						cop += line[i];
					else
					{
						student[n].ID = change(cop);
						cop = "";
						f++;
					}
				}
				else
					cop += line[i];
			}
			if (i == line.length() - 1)
				student[n++].salary = change(cop);
		}
	}
	for (int i = 0; i < n; i ++)
		for (int j = i + 1; j < n; j++)
			if (student[i].salary > student[j].salary)
			{
				b = student[i];
				student[i] = student[j];
				student[j] = b;
			}
	cout << "--------------------" << endl;
	for (int i = n - 1; i > 0; i--) {
		cout << "Fullname: " << student[i].name << endl << "ID: " << student[i].ID << endl << "Salary: " << student[i].salary << endl;
		cout << "--------------------" << endl << "--------------------" << endl;
	}
	cout << "Fullname: " << student[0].name << endl << "ID: " << student[0].ID << endl << "Salary: " << student[0].salary << endl;
	cout << "--------------------";
}
int main()
{
	process("fileName.txt");
	return 0;
}
