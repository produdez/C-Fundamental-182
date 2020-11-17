#include <iostream>;
using namespace std;
main(){

cout<<"Insert a positive number for detailed examine: ";
unsigned int num;
cin>>num;
cout<< "Don vi "<<num%10<<"Chuc "<<(num%100-num%10)/10<<"Tram "<<(num%1000-num%100)/100<<"\n";

}
