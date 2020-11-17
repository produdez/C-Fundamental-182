/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08000_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sat May 04 23:07:04 2019

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08000_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student may define something as need
// TODO




/* With the given fileName, read that file and then process the data,
return true if the file exist,else return false. */
bool process(const char* fileName) {
        cout << setw(10) << left << "Number";
	cout << left << "Count" << endl;

	ifstream file(fileName);
	int z;
	int b[100];
	int k = 0;
	if (!file.good()) return false;
	string a;
	while (file.good())
	{
		file >> b[k];
		k++;
	}
	int res = 1;
	int c[100];
	c[0] = b[0];
	for (int i = 1; i < k-1; i++) {
		int j = 0;
		for (j = 0; j < i; j++)
			if (b[i] == b[j])
				break;
		if (i == j)
		{
			res++;
			c[res - 1] = b[i];
		}
	}
	int temp;
	for (int i = 0; i < res - 1; i++)
	{
		for (int j = i + 1; j < res; j++)
		{
			if (c[j] < c[i])
			{
				temp = c[j];
				c[j] = c[i];
				c[i] = temp;
			}
		}
	}


	for (int i = 0; i < res; i++)
	{
		int d = 0;
		for (int j = 0; j < k; j++)
		{
			if (b[j] == c[i])
			{
				d++;
			}
		}
		if (i == res - 1)
		{
			cout << setw(10) << left << c[i];
			cout << left << d;
			break;
		}
		cout << setw(10) << left << c[i];
		cout << left << d << endl;
	}

	return true;

}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"..", "~/", "expect"};
    fstream ifs;
    ifs.open("main.cpp", ios::in);
    if (ifs.fail()) ifs.open(FILENAME, ios::in);
    if (ifs.fail()) return true;
    ifs.seekg(0, ifs.end);
    int fileSize = ifs.tellg();
    ifs.seekg(0, ifs.beg);
    char* fileContent = new char[fileSize];
    ifs.read(fileContent, fileSize);
    ifs.close();
    *strstr(fileContent, "bool codeCheck() {") = '\0';
    char* todoSegment = strstr(fileContent ,"// Begin implementation");
    int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char*);
    for (int i = 0; i < numberOfForbiddenKeyword; i++) { if (strstr(todoSegment, forbiddenKeyword[i])) return false; }
    delete[] fileContent;
    return true;
}

int main(int argc, char* argv[]) {
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2) return 0;

    try {
        process(argv[1]);
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

