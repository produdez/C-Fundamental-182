#include<iostream>

using namespace std;
main(){
cout<<"Nhap the shiet co 3 chu so: ";
int num,a,b,c,result;
cin>> num;
c=num%10;
b=(num%100-num%10)/10;
a=(num%1000-num%100)/100;
result=c*100+b*10+a;
cout<<"ket qua: "<<result<<"\n";
}
