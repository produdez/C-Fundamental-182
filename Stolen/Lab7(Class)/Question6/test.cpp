#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004b_sol.cpp"
using namespace std;


//.................Class............
class String {
	char* textBuffer;
public:
    String();
    String(const char * text);
	~String();
	//Prototypes only
    //To do...

    //functions
    int length();
    char* toUpper();
    char* toLower();
    //operators
    String& operator=(const char*);
    String operator+(String);
    char& operator[](int);

};
//..................Global functions..........
void process(char* _firstName, char* _lastName);
String toString(const char*);
bool codeCheck();
//................Main...........





int main()
{
    if (codeCheck() == false) {
            cout << "Forbidden-keyword rule violation." << endl;
            return -1;
        }
    process("John","Thompson");
}
//................Implement Class..........






String::String() //default constructor
{
    textBuffer='\0';
}
String::String(const char* text) //constructor with char*
{
    int Size=0;
    while(text[Size]!='\0') Size++;

    textBuffer= new char[Size+1];
    for(int i=0;i<Size;i++)
    {
        textBuffer[i]=text[i];
    } textBuffer[Size]='\0';
}
String::~String() { //destructor
    delete[] this->textBuffer;
    }
String& String::operator=(const char* text)
{
    int Size=0;
    while(text[Size]!='\0') Size++;

    textBuffer= new char[Size+1];
    for(int i=0;i<Size;i++)
    {
        textBuffer[i]=text[i];
    } textBuffer[Size]='\0';
}
String String::operator+(String obj)
{
    int n=this->length();
    int m=obj.length();

    char* a= new char[m+n+1];
    for(int i=0;i<m+n;i++)
    {
        if(i<n) a[i]=textBuffer[i];
        else a[i]= obj.textBuffer[i-n];
    } a[m+n]='\0';
    return String(a);
}
char& String::operator[](int n)
{
    return textBuffer[n];
}
char* String::toUpper()
{
    for(int i=0;i<this->length();i++)
    {
        if(islower(textBuffer[i]))
            textBuffer[i]-=32;
    }
    return textBuffer;
}
char* String::toLower()
{
    for(int i=0;i<this->length();i++)
    {
        if(isupper(textBuffer[i]))
            textBuffer[i]+= 32;
    }
    return textBuffer;
}
int String::length()
{
    int n=0;
    while(textBuffer[n]!='\0') n++;
    return n;
}
//................Implement Global function.........
String toString(const char* text)
{
    return String(text);
}

void process(char* _firstName, char* _lastName) {


	String fName; //default cons


	fName = _firstName; // = operator


	String lName = _lastName; // constructor(char*)


	String name = fName + toString(" ") + lName; // + operator and function toString


	int len = name.length(); //length function


	for (int i = 0; i < len; i++) cout << name[i]; // [] operator


	cout << endl;


	cout << name.toUpper() << endl;  //toUpper and toLower functions


	cout << name.toLower() << endl;


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
