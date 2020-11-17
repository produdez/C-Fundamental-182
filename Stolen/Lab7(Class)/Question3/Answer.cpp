#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07002_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
    Integer () {}
	// Methods prototypes only
    //TODO
    Integer(int n);
    ~Integer();
    int getValue();
    operator int(){return value;}
    };

/**
 * Student implement Integer's methods here
*/

//TODO
Integer::Integer(int n)
{
    value=n;
}
Integer::~Integer()
{
    return;
}
int Integer::getValue()
{
    return value;
}

Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}



main(){
Integer* i= new Integer[6];
Integer n=6;
i[1]=Integer(3);
i[0]=Integer(2);
i[2]=Integer(7);
i[3]=Integer(5);
i[4]=Integer(213);
i[5]=Integer(7);
cout<<max(i,n).getValue()<<endl;


    return 0;
}

