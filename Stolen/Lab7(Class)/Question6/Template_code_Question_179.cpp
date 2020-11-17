/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07004b_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Fri Apr 26 15:55:21 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004b_sol.cpp"
using namespace std;

/* Please note that your code MUST NOT contain any words in the list
{"include", "string", "strcpy", "strlen"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

class String {
	char* textBuffer;
public:
	~String();
	//Prototypes only
    #TODO

};

String::~String() { delete[] this->textBuffer; }

//Methods and friend functions implementation
#TODO


void process(char* _firstName, char* _lastName) {
	String fName;
	fName = _firstName;
	String lName = _lastName;
	String name = fName + toString(" ") + lName;
	int len = name.length();
	for (int i = 0; i < len; i++) cout << name[i];
	cout << endl;
	cout << name.toUpper() << endl;
	cout << name.toLower();
}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include", "string", "strcpy", "strlen"};
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
    ifstream fileIn;
    try {
        fileIn.open(argv[1]);
        if (fileIn.fail()) throw "Failed to open file.";
        string line;
        getline(fileIn, line);
		if (line.length() > 0) if (line[line.length() - 1] == 13) line.pop_back();
        char* firstName = new char[line.length() + 1];
        strcpy(firstName, line.c_str());
        getline(fileIn, line);
		if (line.length() > 0) if (line[line.length() - 1] == 13) line.pop_back();
        char* lastName = new char[line.length() + 1];
        strcpy(lastName, line.c_str());
        process(firstName, lastName);
        fileIn.close();
        delete[] firstName;
    }
    catch (const char* errMsg){
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

