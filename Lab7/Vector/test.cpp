#include"vector_def.h"
//#include"vector.cpp" // needed if files not opened as a project!
#include<iostream>

int main(){
    MyVector a;  //real capacity: 5
    MyVector b(5); //real capacity: 8
    MyVector c=a;
    MyVector d(0); //real capacity: 3

    std::cout<<"Initial vectors: a ... b ... c ... d..."<<std::endl;
    for(int i=0;i<30;i++)
    {
        a.push_back(i);
    } a.print_vector();

    for(int i=0;i<5;i++)
    {
        b.push_back(20);
    } b.print_vector();

    for(int i=0;i<5;i++)
    {
        c.push_back(i);
    } c.print_vector();

    for(int i=0;i<8;i++)
    {
        d.push_back(123456);
    } d.print_vector();

    std::cout<<"Plus-operator"<<std::endl;
    std::cout<<"a+b"<<std::endl;
    (a+b).print_vector();
    std::cout<<"b+c"<<std::endl;
    (b+c).print_vector();
    std::cout<<"c+d"<<std::endl;
    (c+d).print_vector();

    std::cout<<"Dot-operator"<<std::endl;
    std::cout<<"a*b"<<std::endl;
    std::cout<<(a*b)<<std::endl;
    std::cout<<"c*b"<<std::endl;
    std::cout<<(c*b)<<std::endl;
    std::cout<<"d*a"<<std::endl;
    std::cout<<(d*a)<<std::endl;

    std::cout<<"Index accessing!"<<std::endl;
    std::cout<<"a[6] ="<<a[6]<<std::endl;
    std::cout<<"c[0] ="<<c[0]<<std::endl;

    std::cout<<"Changing index"<<std::endl;

    a[10]=999;
    a.print_vector();


return 0;
}
