#include <iostream>
using namespace std;
#define swape(type,a,b){type tmp=a; a=b; b=tmp;}
main(){
cout<< "Lets swap two numbers, shall we? ---- Please insert: ";
float a,b;
cin>> a>>b;
cout <<"Before.....First: "<<a<<" Second: "<<b<<"\n";
swape(float,a,b);
cout <<"After......First: "<<a<<" Second: "<<b<<"\n";
}
