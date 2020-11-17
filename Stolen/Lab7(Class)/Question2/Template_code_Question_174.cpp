/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07001b_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Fri Apr 26 13:24:35 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07001b_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any words in the list
{"include", "string"} even in the comments */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
    //Prototypes only
    //TODO
    Integer(double d);
    Integer();
    ~Integer();
    void toString(char* &c);


};

//Methods implementation
//TODO
Integer::Integer(double d)
{
    value=int(d);
}

Integer::Integer()
{
    value=0;
}
Integer::~Integer()
{
    return;
}


void Integer::toString(char* &c)
{
    int i=value > 0 ? (int) log10 ((double) value) + 1 : 1;
    c= new char[i+1];
    int temp=0;
    c[i]='\0';
    for(int j=0;j<i;j++)
    {
        c[i-j-1]='0'+value%10;
        value/=10;
    }
}
void process(double d) {
	Integer i = d;
	char* c = NULL;
	i.toString(c);
	cout << c;
	delete[] c;
}

bool codeCheck() {
    const char* forbiddenKeyword[] = {"include", "string"};
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
//
//    if (codeCheck() == false) {
//        cout << "Forbidden-keyword rule violation." << endl;
//        return -1;
//    }
    double d= 1312360000;
    Integer i = d;
	char* c = NULL;
	i.toString(c);
	cout << c;
	delete[] c;
    // Section: read testcase
//    ///Student may comment out this section for local testing
//    if (argc < 2) return 0;
//    ifstream fileIn;
//    try {
//        fileIn.open(argv[1]);
//        if (fileIn.fail()) throw "Failed to open file.";
//        double d;
//        fileIn >> d;
//        process(d);
//        fileIn.close();
//    }
//    catch (const char* errMsg){
//        cerr << errMsg;
//    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}

