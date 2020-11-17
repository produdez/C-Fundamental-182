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
	//The constructor
	Integer(int _value);
    bool operator == (int b);
	void operator = (Integer b);
	void operator = (int b);
	Integer operator + (int b);
	bool operator < (Integer b);
	bool operator > (Integer b);
	operator int();
	int getValue();
};
Integer::Integer(int _value) {
    value = _value;
}
int Integer::getValue() {
	return value;
}
Integer::operator int () {
	return value;
} 
bool Integer::operator ==(int b) {
	if (value == b)
		return true;
	else
		return false;
}
Integer Integer::operator +(int b) {
	Integer c(0);
	c.value = value + b;
	return c;
}
void Integer::operator =(Integer b) {
	value = b.value;
}
void Integer::operator =(int b) {
	value = b;
}
bool Integer::operator <(Integer b) {
	if (value < b.value)
		return true;
	else
		return false;
}
bool Integer::operator >(Integer b) {
	if (value > b.value)
		return true;
	else
		return false;
}
//Hàm Integer Max không the bi thay doi
Integer max(Integer* arr, Integer numberOfElements) {


if (arr == NULL || numberOfElements == 0) return Integer(-1);


Integer max = arr[0];


for (Integer i = 0; i < numberOfElements; i = i + 1) {


if (arr[i] > max) max = arr[i];


}


return max;


}
int main()
{
    Integer a(10);
    Integer b[10] = {Integer(1), Integer(2), Integer(3), Integer(54), Integer(590), Integer(650), Integer(12), Integer(47), Integer(8) , Integer(10)};
    cout << max(b, a).getValue();
    return 0;
}
