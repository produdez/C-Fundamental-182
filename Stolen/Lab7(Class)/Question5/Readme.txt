#ID : 178    Question 4Number of sumissions: 0/50Expired time: 2019-05-24 12:15:00
Ceasar cipher is the most popular encoding method of all time. Search for "Ceasar cipher" information and ask your tutor if you still cannot understand it.


Given CaesarMessage class as follows:


class CaesarMessage {

char* textBuffer; //point to dinamic array of chars (decoded message)


public:

CaesarMessage(); //constructor

CaesarMessage(CaesarMessage& obj); //copy constructor

~CaesarMessage(); //delete our saved data in textBuffer : char* []


void encode(const char* _message, int _shift); // lowercase all chars, remove non_char and do shifting, store in our obj's textBuffer

void decode(int _shiftKey, char*& _textContainer); // decode from the obj's textBuffer* according to the shiftkey and store in an outside _textContainer!


};


In which:


- The overloaded constructor CaesarMessage(CaesarMessage& obj) defines how an object is copied to another object.


- "encode" method is about encoding "_message" argument and store the encoded text in "textBuffer" attribute.


- "decode" method is about decoding "textBuffer" and save the original text in "_textContainer".


Write completed code for all constructors, destructor, encode, and decode method.


Note: for encode method, you should lower case all the characters and then do the shifting. Just encode the alphabet, ignore any others. It means if a charater is not an alphabet character, you do not need to keep them in textBuffer. For example: "Today is hot!", after encoding and decoding will become "todayishot".