#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
void process(const char* fileName) {
	ifstream fileIO;
	fileIO.open(fileName);
	int n = 0, a[26] = { 0 }, b = 0;
	string line;
	while (!fileIO.eof())
	{
		getline(fileIO, line);
		n++;
		for (int i = 0; i < line.length(); i++)
		{
			b = toupper(line[i]) - 65;
			a[b]++;
		}
	}
	cout << "Lines = " << n << endl;
	for (int i = 0; i < 25; i++)
		cout << char(i + 65) << " = " << a[i] << endl;
	cout << char(25 + 65) << " = " << a[25];
}
int main()
{
	process("fileName.txt");
	return 0;
}