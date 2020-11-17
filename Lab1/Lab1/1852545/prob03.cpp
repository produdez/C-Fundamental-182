#include <iostream>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
main(){
cout<<"Input a positive interger: ";
unsigned int n;
cin>>n;
int number;
srand(time(NULL)); //take a seed
number = (rand() %(2*n))-n; //get random number in the range
cout<<"A random number in the range ["<<-n<<", "<<n<<"] :"<< number<<"\n";
}
