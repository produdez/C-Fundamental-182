#include <iostream>

using namespace std;

class Complex
{
private:
    double real,imagine;
public:
    Complex(){real=0;imagine=0;}
    Complex(double a,double b) // default declare;
    {
        real=a;
        imagine=b;
        cout<<"OBJ created!"<<endl;
    }

    Complex Add(Complex b) // current + b
    {
        Complex c;
        c.real=real+b.real;
        c.imagine=imagine+b.imagine;
        return c;
    }
    Complex Subtract(Complex b) // current - b
    {
        Complex c;
        c.real=real-b.real;
        c.imagine=imagine-b.imagine;
        return c;
    }

    void Print() {
        cout<<'('<<real<<','<<imagine<<')';
    }

    ~Complex() {}

};


int main(){
    Complex a(1,2),b(3,4);
    a.Add(b).Print();

}
