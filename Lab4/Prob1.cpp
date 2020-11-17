#include <iostream>
using namespace std;
main()
{
int a[ 3 ];
cout << a[ 1 ] << " " << a[ 2 ] << " " << a[ 3 ] << endl; // The array only have 3 element from 0-2 so, the variable a[3] doesnt exists

double f[ 3 ] = { 1.1, 10.01, 100.001, 1000.0001 }; // Only 3 memory slots in the array but you try to declare 4 numbers, which is wrong
double d[ 2 ][ 10 ];
d[ 1, 9 ] = 2.345; // The right line is d[1][9]=2.345;
}
