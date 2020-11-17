#include <iostream>
using namespace std;
class Polygon{
public:
Polygon(){}
 ~Polygon(){cout<<"Poli dead"<<endl;};

virtual void getArea(){cout<<"Poly"<<endl;}

};

class Rectangle : public Polygon {
public:
Rectangle(){}
virtual ~Rectangle(){cout<<"Rec dead"<<endl;}

void getArea(){cout<<"Rec"<<endl;}
};

class Square : public Rectangle {
public:
Square(){}
~Square(){cout<<"Square dead"<<endl;}

void getArea(){cout<<"Square"<<endl;}
};

main(){

    Polygon * p = new Rectangle();

    p->getArea();

return 0;
}
