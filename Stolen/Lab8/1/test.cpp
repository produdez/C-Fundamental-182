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

bool process(const char* fileName) {
    ifstream input;
    input.open(fileName,ifstream::in);
    if(!input.is_open()) return 0;

    int a[100]{0};
    int numCount=0;

    //count all numbers and input into a
    while(1)
    {
        input>>a[numCount];
        if(a[numCount]==-999) break;
        numCount++;
    }
    int temp=-1;

    //sorting
    for(int i=0;i<numCount;i++)
    {
        for(int j=i+1;j<numCount;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            temp=-1;
        }

    }

    //printing
    int occ=1;
    for(int i=0;i<numCount-1;i++)
    {
        if(a[i]==a[i+1]&&i!=numCount-2) occ++;
        else
        {
            cout<<a[i]<<setw(10)<<occ<<endl;
            occ=1;
        }

    }
    input.close();
    return 1;

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

    // Manual test
        process("testCase.txt");

}
