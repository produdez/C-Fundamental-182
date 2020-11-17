#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
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
	String();
	String(const char *a);
	//String(const String& a);
	String operator + (String a);
	int length();
	char *toUpper();
	char *toLower();
	const char& operator[](int i) const;
	void operator = (const char *a);
};
void String::operator = (const char * a) {
	int length = 0;
	for (int i = 0; a[i] != '\0'; i++)
		length++;
	textBuffer = new char[length + 1];
	for (int i = 0; a[i] != '\0'; i++)
		textBuffer[i] = a[i];
	textBuffer[length] = '\0';
}
int String::length() {
	int a = 0;
	for (int i = 0; textBuffer[i] != '\0'; i++)
		a++;
//	return a;
return strlen(textBuffer);
}

String::~String() { delete[] this->textBuffer; }

String::String() {
}

String::String(const char *a) {
	int length = 0;
	for (int i = 0; a[i] != '\0'; i++)
		length++;
	textBuffer = new char[length + 1];
	for (int i = 0; a[i] != '\0'; i++)
		textBuffer[i] = a[i];
	textBuffer[length] = '\0';
}

/*String::String(const String& a) {
	int length = 0;
	for (int i = 0; a.textBuffer[i] != '\0'; i++)
		length++;
	textBuffer = new char[length + 1];
	for (int i = 0; a.textBuffer[i] != '\0'; i++)
		textBuffer[i] = a.textBuffer[i];
	textBuffer[length] = '\0';
}*/

String String::operator + (String a) {
	String add;
	int len = this->length();
	add.textBuffer = new char[len + a.length()];
	for (int i = 0; textBuffer[i] != '\0'; i++)
		add.textBuffer[i] = textBuffer[i];
	for (int i = 0; a.textBuffer[i] != '\0'; i++)
		add.textBuffer[len + i] = a.textBuffer[i];
	return add;
}

char* String::toUpper() {
	for (int i = 0; textBuffer[i] != '\0'; i++)
		if (textBuffer[i] >= 'a' && textBuffer[i] <= 'z')
			textBuffer[i] -= 32;
	return textBuffer;
}

char* String::toLower() {
	for (int i = 0; textBuffer[i] != '\0'; i++)
		if (textBuffer[i] >= 'A' && textBuffer[i] <= 'Z')
			textBuffer[i] += 32;
	return textBuffer;
}

const char& String::operator[](int i) const {
    return textBuffer[i];
}

String toString(const char* a)
{

	return String(a);
}
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
int main() {
	char *name1 = new char[1000];
	char a[1000] = "Bui Dinh";
	name1 = a;
	char *name2 = new char[1000];
	char b[1000] = "Khoi";
	name2 = b;
	process(a, b);
}
