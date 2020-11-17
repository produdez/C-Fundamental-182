#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int GreatestDiv(int a, int b) { // Greatest common divisor
   if (b == 0)
   return a;
   return GreatestDiv(b, a % b);
}
int SmallestMut(int a, int b) // Smallest common multiplier
 {
    return (a*b)/GreatestDiv(a, b);
 }


class Rational
{
private:
    int num;
    int den;

public:
    // CONSTRUCTOR
    Rational(){
        num=0;
        den=1;
    }
    Rational(int a,int b)
    {
        if(b==0){
            cout<<"Error!:Denominator can not be zero!"<<endl;
        }else{
            num=a/GreatestDiv(a,b);
            den=b/GreatestDiv(a,b);
        }
    }

    //Math functions
    Rational Adding(Rational b)
    {
        int x=SmallestMut(den,b.den);
        Rational c(num*x/den+b.num*x/b.den,x);
        return c;
    }
    Rational Subtracting(Rational b)
    {
        int x=SmallestMut(den,b.den);
        Rational c((num*x/den)-(b.num*x/b.den),x);
        return c;
    }
    Rational Multiplying(Rational b)
    {
        Rational c(num*b.num,den*b.den);
        return c;
    }
    Rational Dividing(Rational b)
    {
        Rational c(num*b.den,den*b.num);
        return c;
    }

    //Print Function
    void PrintR(){
        if(num==den) cout<<1<<endl;
        else if(num==0) cout<<0<<endl;
        else cout<<num<<'/'<<den<<endl;
    }
    void PrintF(){
        cout<<float(num)/den<<endl;
    }
    //Operator Overload Functions
    Rational operator+(Rational b){
        return (*this).Adding(b);
    }
    Rational operator-(Rational b){
        return (*this).Subtracting(b);
    }
    Rational operator*(Rational b){
        return (*this).Multiplying(b);
    }
    Rational operator/(Rational b){
        return (*this).Dividing(b);
    }

    //Destructor
    ~Rational(){
    }
};



int main(){
    Rational a=Rational(1,2);
    Rational b=Rational(6,9);
    a.Adding(b).PrintR();
    a.Subtracting(b).PrintR();
    a.Multiplying(b).PrintR();
    a.Dividing(b).PrintR();

    (a+b).PrintF();
    (a-b).PrintF();
    (a*b).PrintF();
    (a/b).PrintF();

   /* int x,y;  // For testing :3
    while(1)
    {
        cout<<"a/b=?";
        cin>>x>>y;
        Rational* c;
        c=new Rational(x,y);
        c->PrintR();
        c->PrintF();
    } */
}
