#include <iostream>
#include <vector>
using namespace std;

//Class declaration

//base
class LivingCreature
{
protected:
public:
    virtual void setName(char*)=0;
    virtual char* getName()=0;
    virtual char* getObjType()=0;
};
//derived1
class Human: public LivingCreature
{
    char* name;
    char* birthday;
    int age;
public:
    Human();
    void setName(char*);
    char* getName();
    char* getObjType();
};
class Animal:public LivingCreature
{
protected:
    char* name;
public:
    Animal();
    void setName(char*);
    char*getName();
};
//derived2
class Dog: public Animal
{
public:
    char* getObjType();
};
class Lion: public Animal
{
public:
    char* getObjType();
};
//..............main......
int main()
{
    vector<LivingCreature*> objArr(3);
    objArr[0]= new Dog;
    objArr[1]= new Lion;
    objArr[2]= new Human;

    objArr[0]->setName("Ditto");
    objArr[2]->setName("Prod");

    for(int i=0;i<3;i++)
    {
        cout<<objArr[i]->getName()<<endl;
        cout<<objArr[i]->getObjType()<<endl;
        cout<<"----------------------"<<endl;
    }

    return 0;
}
//................................
//Class implement

//derived 1
char* Human::getName()
{
    if(name=="NoName") return "Unknown";
    else return name;
}
char* Human::getObjType()
{
    return "Human";
}
Human::Human()
{
    name="NoName";
}
void Human:: setName(char* a)
{
    name= a;
}
char* Animal::getName()
{
    if(name=="NoName") return "Unknown";
    else return name;
}
Animal::Animal()
{
    name="NoName";
}
void Animal::setName(char* a)
{
    name=a;
}

//derived 2
char* Dog::getObjType()
{
    return "Dog";
}
char* Lion::getObjType()
{
    return "Lion";
}
