#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004_sol.cpp"
using namespace std;


//Class define
class CaesarMessage {
	char* textBuffer;
public:
	CaesarMessage();
	CaesarMessage(CaesarMessage& obj);
	~CaesarMessage();
	void encode(const char* _message, int _shift);
	void decode(int _shiftKey, char*& _textContainer);
};
//Global function
void process(CaesarMessage msg, int shiftKey, char*& container);
bool codeCheck() {
    const char* forbiddenKeyword[] = {"include"};
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

//Main
int main(){
    if (codeCheck() == false) {
        cout << "Forbidden-keyword rule violation." << endl;
        return -1;
    }
    //..........................
CaesarMessage a;
char* _message= "Using the special cock-edition, Harry was able to knock Marge up after only 15 minutes on bed!!";
a.encode(_message,7);
char* _decoded;
a.decode(4,_decoded);
//char b='t'+7-26;
cout<<_decoded<<endl;
return 0;
}



//Implementation
CaesarMessage::CaesarMessage() { // default constructor
    //does nothing
    textBuffer='\0';
}


CaesarMessage::CaesarMessage(CaesarMessage& obj) { //copy constructor
// create new dynamic array and copy point the pointer to it

    int n=0;
    while(obj.textBuffer[n]!='\0') n++; //count length of previous obj's string

    textBuffer= new char[n+1]; //extra slot for null char at the end
    //copy all string's contents
    for(int i=0;i<n;i++)
    {
        textBuffer[i]= obj.textBuffer[i];
    } textBuffer[n]='\0';
}

/* The destructor */
CaesarMessage::~CaesarMessage() {
	/* You have to tidy the dynamic memory, right?
	But, wait! What will happen if the textBuffer has been deleted already?
	Can that problem happen? When, why? And what is the solution? */
	cout<<"deleted!"<<endl;
	delete[] this->textBuffer;
	this->textBuffer = NULL;
}

/* Encode the input message and then store the result in the textBuffer */
void CaesarMessage::encode(const char* _message, int _shift) {
	/* Guide: Lower case all the characters and then do the shifting.
	Just encode the alphabet, ignore any others */
    int n=0;
    while(_message[n]!='\0') n++;

    textBuffer= new char[n+1];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(isalpha(_message[i]))
        {
            if(islower(_message[i]))
            {
                textBuffer[j]=_message[i]+ _shift;
                if(!islower(textBuffer[j]))
                {
                    textBuffer[j]=_message[i]+(_shift-26);
                }
                j++;
            }else //if upper
            {
                textBuffer[j]=_message[i]+32 + _shift;
                if(!isupper(textBuffer[j]))
                {
                    textBuffer[j]=_message[i]+(_shift-26)+32;
                }
                j++;
            }
        }
    }
    textBuffer[j]='\0';

}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char*& _textContainer) {
//
    int n=0;
    while(textBuffer[n]!='\0')n++;

    _textContainer= new char[n+1];
    for(int i=0;i<n;i++)
    {
        _textContainer[i]=textBuffer[i]-_shiftKey;
        if(!islower(_textContainer[i]))
        {
            _textContainer[i]=textBuffer[i]-(_shiftKey-26);
        }
    }
    _textContainer[n]='\0';
}

/* Notice this function */
void process(CaesarMessage msg, int shiftKey, char*& container) {
    msg.decode(shiftKey, container);
}

