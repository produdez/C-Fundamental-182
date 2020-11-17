#include<iostream>
#include <iomanip>
using namespace std;
main(){
cout<<"Time in seconds?";
int second;
cin>>second;
int hh,mm,ss;
hh=second/3600;
mm=second/60-hh*60;
ss=second-hh*3600-mm*60;
cout<<"The time elapsed: \n";
cout<<setfill('0')<<setw(2)<<hh<<" : ";
cout<<setfill('0')<<setw(2)<<mm<<" : ";
cout<<setfill('0')<<setw(2)<<ss<<"\n";
}
