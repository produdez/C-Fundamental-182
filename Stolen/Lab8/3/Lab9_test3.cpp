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
	int n = 0;
	string line;
	while (!fileIO.eof())
	{
		fileIO >> line;
		n++;
	}
}
int main()
{
	process("fileName.txt");
	return 0;
}