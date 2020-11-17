#include<iostream>
#include<cstring>
using namespace std;
class Patient
{
private:
int idNumber;
public:
void setIdNumber(int idIn);
int getIdNumber();
};
void Patient::setIdNumber(int idIn)
{
idNumber = idIn;
}
int Patient::getIdNumber()
{
return idNumber;
}

class Dog
{
private:
string breed;
public:
void setBreed(string breedIn);
string getBreed();
};
void Dog::setBreed(string breedIn)
{
breed = breedIn;
}
string Dog::getBreed()
{
return breed;
}

class Pet: public Patient, public Dog
{
    string name;
public:
    void setName(string _name);
    string getName ();
};

void Pet::setName(string _name)
{
    name=_name;
}
string Pet::getName()
{
    return name;
}

int main()
{

Pet p1;
p1.setName("Kali");
p1.setIdNumber(44444);
p1.setBreed("Aussie");
cout << p1.getName() << " " << p1.getIdNumber() << " " << p1.getBreed();
return 0;

}
