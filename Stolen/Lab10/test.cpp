#include <iostream>
using namespace std;


//...........Classes declaration...............
class Employee
{
	protected:
		int id;
		string name;
		string dateOfBirth; //mmddyyyy format
	public:
		Employee(int _id, string _name, string _dateOfBirth);
		void print();
		virtual int calculateSalary()=0;
};
//............ Sorting class........
class sorting: public Employee
{
public:
    sorting(int id,string name,string day):Employee(id,name,day){};
    string getName()
    {
        return name;
    }

};
// Other classes
class Secretary : public sorting
{
    int bonus;
    int daysOff;
public:

    Secretary(int _id,string _name,string _dateOfBirth,int _bonus,int _daysOff):sorting(_id,_name,_dateOfBirth){
        bonus=_bonus;
        daysOff=_daysOff;
    };
    int calculateSalary();
};
class Sales : public sorting
{
    int totalSales;
public:

    Sales(int _id,string _name,string _dateOfBirth,int _totalSales):sorting(_id,_name,_dateOfBirth){
        totalSales=_totalSales;
    };
    int calculateSalary();
};
class Manager : public sorting
{
    int bonus;
public:
    Manager(int _id,string _name,string _dateOfBirth,int _bonus):sorting(_id,_name,_dateOfBirth){
        bonus=_bonus;
    };
    int calculateSalary();
};

//...........Global variables...............
    void createEmploy(sorting**& a);
    void switchE(sorting* &a, sorting*&b)
    {
        sorting* temp= nullptr;
        temp=a;
        a=b;
        b=temp;
        temp=nullptr;
    }

    void sortEmployeeList(sorting**a,int n)
    {
        int check;
        sorting* temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                check=a[i]->getName().compare(a[j]->getName());
                if(check=1)
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    temp=nullptr;
                }
            }
        }
    }

//.......................................
int main()
{
    sorting** list;
    createEmploy(list);
    int n=8;
    for(int i=0;i<n;i++)
    {
        list[i]->print();
    }
    sortEmployeeList(list,n);
    for(int i=0;i<n;i++)
    {
        list[i]->print();
    }
    return 0;
}

//.............................
int Secretary::calculateSalary()
{
    return 3000000+ bonus - daysOff*100;
}
int Sales::calculateSalary()
{
    return 2000000 + totalSales*0.1;
}
int Manager::calculateSalary()
{
    return 4000000 + bonus;
}

Employee::Employee(int _id, string _name, string _dateOfBirth)
{
	this->id = _id;
	this->name = _name;
	this->dateOfBirth = _dateOfBirth;
}

void Employee::print()
{
	cout<<"Employee's ID: "<< this->id<<"\n";
	cout<<"Name: "<<this->name<<"\n";
	cout<<"Date of Birth: "<<this->dateOfBirth<<"\n";
	cout<<"Salary: "<<this->calculateSalary()<<"\n\n";
}
void createEmploy(sorting**& a)
{
    sorting** e= new sorting*[8];
    e[0]= new Secretary(0,"Lara","01012000",3000,2);
    e[1]= new Secretary(1,"Pudding","12121500",1000,0);
    e[2]= new Secretary(2,"Cornie","31053200",2000,10);
    e[3]= new Sales(3,"Pluto","23069999",1560);
    e[4]= new Sales(4,"Carma","10101000",6000);
    e[5]= new Sales(5,"Sett","20102000",9000);
    e[6]= new Sales(6,"Carnot","03033000",200);
    e[7]= new Manager(7,"Produde","55555555",9000);
    a=e;
}
//void sortEmployList(Employee** a,int n)
//{
//    int check;
//    Employee* temp;
//    for(int i=0;i<n;i++)
//    {
//        for(int j=i+1;j<n;j++)
//        {
//            check= a[i]->name.compare(a[j].name);
//            if(check==1) // name i larger alphatically
//            {
//                temp=a[i];
//                a[i]=a[j];
//                a[j]=*temp;
//                temp=nullptr;
//            }
//        }
//    }
//}
