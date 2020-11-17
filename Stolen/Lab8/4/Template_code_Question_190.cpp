/**
	Faculty of Computer Science and Engineering
	Ho Chi Minh City University of Technology
	Programming fundamentals - spring 2019
    Lab 08: 08003_ini.cpp
	@author CSE - HCMUT
	@version 1.0 Sun May 05 16:04:59 2019

*/
#pragma warning (disable: 4996)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08003_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------
struct employ
{
    string name;
    int id;
    int salary;
};

bool compareSalary(employ& a,employ& b)
{
    if(a.salary!=b.salary) return b.salary>a.salary;
    else return b.id>a.id;
}
/// Student may implement something as need


void process(const char* fileName) {
    ifstream input;
    input.open(fileName,ifstream::in);

    string ss;
    int n=0;
    while(!input.eof())
    {
        getline(input,ss);
        n++;
    }
    //reset cursor
    input.seekg(0,input.beg);

    employ* data= new employ[n];
    for(int i=0;i<n;i++)
    {
        getline(input,data[i].name,',');
        input>>data[i].id;
        input.ignore(10,',');
        input>>data[i].salary;
        input.ignore(10,'\n');

    }

    employ temp;
    for(int i=0;i<n;i++)
    {
        temp=data[i];
        for(int j=i+1;j<n;j++)
        {
            if(compareSalary(data[i],data[j]))
            {
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }

        cout<<"-------------------------"<<endl;
        cout<<data[i].name<<endl;
        cout<<data[i].id<<endl;
        cout<<data[i].salary<<endl;
        cout<<"-------------------------"<<endl;
    }


    input.close();

}

bool codeCheck() {
	const char* forbiddenKeyword[] = { "..", "~/", "expect" };
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
	char* todoSegment = strstr(fileContent, "// Begin implementation");
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


	//........ Manual Test..........

    process("test.txt");

	//end..........
	return 0;
}

