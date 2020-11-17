#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
main(){
cout<<"Insert the radius of the circle: ";
const float pi=3.14;
float r;
cin>> r;
float C,S;
S=pi*pow(r,2);
C=2*pi*r;
cout.precision(4);
cout<<scientific<< "Circumference: "<< C<<" or " << fixed <<C<<"\n";
cout<<scientific<< "Area: "<< S<<" or " << fixed <<S<<"\n";
}
