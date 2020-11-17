/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 08: 08001_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Sun May 05 14:24:59 2019

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08001_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------


void process(const char* fileName) {
    ifstream input;
    input.open(fileName,ifstream::in);

    string ss;
    int lineNum=0;
    int letterCount[26]{0};
    while(!input.eof())
    {
        lineNum++;
        getline(input,ss);

        for(int i=0;i<ss.length();i++)
        {
            if(isalpha(ss[i])) letterCount[(ss[i]-'A')%32]++;
        }
    }

    cout<<"Lines = "<< lineNum<<endl;
    for(int i=0;i<26;i++)
    {
        cout<<char(i+65)<<" = "<<letterCount[i]<<endl;
    }

    input.close();

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
   process("test.txt");

//   char a;
//   char b;
//   while(1)
//   {
//     cin>>a;
//     b=(a-'A')%32+'a';
//     cout<<a<<' '<<b;
//   }


    return 0;
}

