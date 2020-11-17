#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct myDay{
    int day;
    int month;
    int year;
  };
struct Student {
    string ID;
    string name;
    string surName;

    myDay birthday;

    char Data[1024];

    };

struct studentlist {
int NumStu;
int MaxStu;
Student Slist[10];
};




main()
{


studentlist SL={5,100,{
    {"132131321","Long","Tran",{14,10,2000},""},
   {"98156166","Mai","Tran",{5,1,1234},""},
    {"884899498","Danh","Thanh",{3,2,3000},""},
    {"98115632132","Bus","Cus",{16,7,1400},""},
    {"16515188994","Ba","Tran",{20,12,1999},""}
}};


}
