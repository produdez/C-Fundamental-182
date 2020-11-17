#include <iostream>
#include <math.h>
using namespace std;
float val;
float foo(float a, float b) {
val += b;
return a * b + val;
}
int main() {
float x, y;
x = 0.5f;
cout << foo(x, y) << endl;
return 0;
}
