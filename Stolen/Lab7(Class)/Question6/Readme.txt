Given String class as follows:



class String {


	char* textBuffer;


public:


	~String();


	


};



String::~String() { delete[] this->textBuffer; }



Write completed code for the above method, so that these following code can run correctly as described in the example.



void process(char* _firstName, char* _lastName) {


	String fName;


	fName = _firstName;


	String lName = _lastName;


	String name = fName + toString(" ") + lName;


	int len = name.length();


	for (int i = 0; i < len; i++) cout << name[i];


	cout << endl;


	cout << name.toUpper() << endl;


	cout << name.toLower() << endl;


}


Example:


Arguments of "process" method:


_firstName: Jack


_lastName: Thompson


Result of "process"method:


Jack Thompson


JACK THOMPSON


jack thompson

