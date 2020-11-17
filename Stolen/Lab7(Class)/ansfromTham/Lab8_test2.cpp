#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;
class Integer {
	int value;
public:
	// The constructor
	Integer(double _value);
    void toString(char *&c);
};
Integer::Integer(double _value) {
    value = _value;
}
void Integer::toString(char *&c) {
    int i = 0;
    char a[100];
    c = new char[100];
    while (true) {
        if (value / 10 == 0) {
            a[i++] = value + 48;
            break;
        }
        a[i++] = value % 10 + 48;
        value /= 10;
    }
    int f = i;
    i--;
    for (int j = 0; j < f; j++)
    	c[j] = a[i--];
    	c[f] = '\0';
}
void process(double d) {


	Integer i = d;


	char* c = NULL;


	i.toString(c);

	//cout << c[3] << endl;
	cout << c;


	delete[] c;


}
int main()
{
    Integer a = Integer(3);
    //process(750.5);
    return 0;
}
