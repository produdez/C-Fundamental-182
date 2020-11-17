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
	char** arr;
	int M, N;
	int n = 0, f = 0;
	ifstream fileIO;
	fileIO.open(fileName);
	fileIO >> M >> N;
	arr = new char*[M];
	for (int i = 0; i < M; i++)
		arr[i] = new char[N];
	while (!fileIO.eof())
	{
		fileIO >> arr[f][n++];
		if (n == N) {
			f++;
			n = 0;
		}
	}  v
	cout << arr[0][6];

}
int main()
{
	process("fileName.txt");
	return 0;
}
